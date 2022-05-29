echo "Building shell"
g++ main.cpp -std=c++11 -o shell
echo "Building shell done"
echo "Version of shell:"
 cat main.cpp | head -n 9 | tail -n 1 | sed 's/std::string VERSION = "//g' | sed 's/";//g' 
echo "Do you want to run the shell? (y/n)"
read answer
if [ $answer = "y" ]
then
    ./shell
fi