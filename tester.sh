#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]; then
    echo "Usage: ./tester.sh <nombre_de_nombres> <limite> <nb_iterations>"
    exit 1
fi

NUMBERS_COUNT=$1
LIMIT=$2
NUM_TESTS=$3
OK_COUNT=0
KO_COUNT=0
TOTAL_LINES=0
KO_FILE="ko_tests.txt"

KO_FILE="ko_tests.txt"

if [ -e "$KO_FILE" ]; then
    rm -rf "$KO_FILE"
fi

for ((i=1; i<=NUM_TESTS; i++))
do
    numbers=$(shuf -i 1-1000000 -n $NUMBERS_COUNT | tr '\n' ' ')
    ARG="$numbers"
    result=$(./push_swap $ARG)
    line_count=$(echo "$result" | wc -l)
    TOTAL_LINES=$((TOTAL_LINES + line_count))
    check=$(echo "$result" | ./checker_linux $ARG)

    if [ "$check" == "OK" ]; then
        if [ "$line_count" -le "$LIMIT" ]; then
            OK_COUNT=$((OK_COUNT + 1))
        else
            KO_COUNT=$((KO_COUNT + 1))
            echo "Test $i: KO (trop de lignes: $line_count)" >> $KO_FILE
            echo "$numbers" >> $KO_FILE
        fi
    else
        KO_COUNT=$((KO_COUNT + 1))
        echo "Test $i: KO" >> $KO_FILE
        echo "$numbers" >> $KO_FILE
    fi
done

if [ $NUM_TESTS -gt 0 ]; then
    AVG_LINES=$(echo "scale=2; $TOTAL_LINES / $NUM_TESTS" | bc)
else
    AVG_LINES=0
fi

if [ $KO_COUNT -eq 0 ]; then
    echo -e "${GREEN}Tous les tests sont OK: $OK_COUNT${NC}"
else
    echo -e "${RED}Nombre de tests OK: $OK_COUNT${NC}"
    echo -e "${RED}Nombre de tests KO: $KO_COUNT${NC}"
    echo -e "${RED}Voir $KO_FILE pour plus de détails.${NC}"
fi

echo -e "Moyenne d'operations de push_swap : ${AVG_LINES}"
