for((i=1;i < 1000;i++));do
	./TestGenerator $i>testInput
	./solution<testInput>solutionOutput
	./brute<testInput>bruteOutput
	diff solutionOutput bruteOutput || break
done