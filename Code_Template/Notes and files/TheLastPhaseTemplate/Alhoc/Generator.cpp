Linux: s.sh
for ((i = 1; i < 100; i++)); do
	. / gen $i > int
	. / a<int>out1
	. / brute<int>out2
	diff out1 out2 || break
	Done
gen.cpp:
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll my_rand(ll l, ll r) {
	return uniform_int_distribution<ll>(l, r) (rng);
}
Windows: checker.bat
@echo off
for / l % % x in (1, 1, 100) do (
		    TestGenerator > input.in
		    solution< input.in > solutionOutput.out
		    brute< input.in > bruteOutput.out
		    fc solutionOutput.out bruteOutput.out > diagnostics || exit / b
		    echo % % x
		)
		echo all tests passed
		:: run solution.cpp and brute.cpp before running checker.bat