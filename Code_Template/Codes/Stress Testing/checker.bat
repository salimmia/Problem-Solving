@echo off
for /l %%x in (1, 1, 100) do (
    TestGenerator > input.in
    solution< input.in > solutionOutput.out 
    brute< input.in > bruteOutput.out
    fc solutionOutput.out bruteOutput.out > diagnostics || exit /b
    echo %%x
)
echo all tests passed

:: run solution.cpp and brute.cpp before running checker.bat