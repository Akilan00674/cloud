read -p "Enter first number: " a
read -p "Enter second number: " b
read -p "Enter third number: " c

smallest=$a

if [ $b -lt $smallest ]; then
    smallest=$b
fi

if [ $c -lt $smallest ]; then
    smallest=$c
fi
echo "Smallest number is: $smallest"

