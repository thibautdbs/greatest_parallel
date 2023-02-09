#!/usr/bin/env bash

################################################################################
### ARGPARSE

function my::put_usage()
{
	echo "usage: greatest_parallel [-v|--verbose] [-j|--jobs JOBSMAX] TEST_RUNNER"
}

declare -a ARGS;
while [[ "$#" -gt 0 ]]; do
	case "$1" in
	-h)
		my::put_usage;
		exit 0;
		;;
	-v|--verbose)
		shift 1;
		declare -r VERBOSE=1;
		;;
	-j|--jobs)
		if [[ ! "$2" =~ ^[0-9]+$ ]]; then
			echo "greatest_parallel: expected positive integer after -j|--jobs." >&2;
			my::put_usage;
			exit 1;
		fi
		JOBSMAX="$2";
		shift 2;
		;;
	-*)
		echo "Unknown option $1." >&2;
		my::put_usage;
		exit 1;
		;;
	*)
		ARGS+=("$1");
		shift 1;
		;;
	esac
done
set -- "${ARGS[@]}";
if [[ "$#" -ne 1 ]]; then
	echo "greatest_parallel: Expected 1 positional arguments." >&2;
	my::put_usage;
	exit 1;
fi

if [[ -z "${JOBSMAX}" ]]; then
	declare -r JOBSMAX=$(nproc);
fi

declare -r RUNNER=${1};
if [[ ! -x "${RUNNER}" ]]; then
	echo "greatest_parallel: ${RUNNER} is not executable." >&2;
	exit 1;
fi

################################################################################
### MAIN

### TMP FILES
declare -r TMP=$(mktemp -d /tmp/greatest_parallel.XXXXXXXX);
if [[ ! -d "${TMP}" ]]; then
	echo "greatest_parallel: couldn't create tmp directory." >&2;
	exit 1;
fi
mkdir -p "${TMP}/SUITES";

function my::teardown()
{
	trap "" EXIT QUIT TERM INT;
	wait;
	rm -rf "${TMP}";
	exit "$1";
}
trap 'my::teardown $?' EXIT QUIT TERM INT;

declare -r SUITES=$(mktemp -p "${TMP}");
declare -r FAILED_SUITES=$(mktemp -p "${TMP}");

### TEST RUNNER
function my::run_suite()
{
	declare -r SUITE="$1";

	declare -r LOG="${TMP}/SUITES/${SUITE}";

	timeout --verbose --kill-after=5s 3s						\
		valgrind --quiet --leak-check=full --show-reachable=yes	\
			"${RUNNER}" -e -s "${SUITE}" >&"${LOG}";

	if [[ "$?" != 0 ]]; then
		flock "${FAILED_SUITES}" -c "echo '${SUITE}' >>'${FAILED_SUITES}'";
	fi
	flock "${SUITES}" -c "echo '${SUITE}' >>'${SUITES}'";
}

function my::log()
{
	sort -u | while read -r SUITE; do
		cat <<-EOF
		================ SUITE: \`${SUITE}\`
		$(cat "${TMP}/SUITES/${SUITE}")

		EOF
	done
}

function my::run_suites()
{
	declare SUITE;
	while read -r SUITE; do
		if [[ "$(jobs | wc -l)" -ge "${JOBSMAX}" ]]; then
			wait -n;
		fi
		my::run_suite "${SUITE}" >&/dev/null &
	done
	wait;

	if [[ "${VERBOSE}" == 1 ]]; then
		my::log <"${SUITES}";
	elif [[ "$(wc -l <"${FAILED_SUITES}")" -gt 0 ]]; then
		my::log <"${FAILED_SUITES}";
	fi

	if [[ "$(wc -l <"${FAILED_SUITES}")" -gt 0 ]]; then
		exit 1;
	fi
}

"${RUNNER}" -l | sed -nr 's|^\* Suite (.+):$|\1|p' | my::run_suites;
