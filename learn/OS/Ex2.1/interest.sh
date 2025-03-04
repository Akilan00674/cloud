read -p "Enter Principal Amount: " P
read -p "Enter Rate of Interest: " R
read -p "Enter Time (in years): " T

SI=$(echo "scale=2; ($P * $R * $T) / 100" | bc)
echo "Simple Interest: $SI"

