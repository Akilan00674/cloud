calculate() {
    case $2 in
        "+") result=$(echo "$1 + $3" | bc) ;;
        "-") result=$(echo "$1 - $3" | bc) ;;
        "*") result=$(echo "$1 * $3" | bc) ;;
        "/") result=$(echo "scale=2; $1 / $3" | bc) ;;
        "%") result=$(echo "$1 % $3" | bc) ;;
        *) echo "Invalid operator"; exit 1 ;;
    esac
    echo "Result: $result"
}

read -p "Enter first number: " num1
read -p "Enter operator (+, -, *, /, %): " op
read -p "Enter second number: " num2

calculate $num1 "$op" $num2

