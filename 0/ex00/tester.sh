YELLOW='\033[0;33m'
NC='\033[0m'

make

echo Test 1:
INPUT="shhhhh... I think the students are asleep..."
EXPECTED1="SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
echo "${YELLOW}INPUT: $INPUT${NC}"
echo "${YELLOW}EXPECTED: $EXPECTED1${NC}"
./megaphone "$INPUT" | cat -e
echo

echo Test 2: Multiple arguments
INPUT='Damnit " ! " "Sorry students, I thought this thing was off."'
EXPECTED2="DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
echo "${YELLOW}INPUT: $INPUT${NC}"
echo "${YELLOW}EXPECTED: $EXPECTED2${NC}"
eval ./megaphone $INPUT | cat -e
echo

echo Test 3: No arguments
INPUT=''
EXPECTED3="* LOUD AND UNBEARABLE FEEDBACK NOISE *"
echo "${YELLOW}INPUT: $INPUT${NC}"
echo "${YELLOW}EXPECTED: $EXPECTED3${NC}"
./megaphone | cat -e
echo

# Cleanup
make fclean > /dev/null
