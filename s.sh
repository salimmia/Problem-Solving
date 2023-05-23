for((i=1; ;++i));do
    echo $i
    ./generator $i >int
    ./solution < int > user
    ./brute < int > Accepted
    diff user Accepted || break
done
