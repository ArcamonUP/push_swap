#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

if [ -z "$1" ]; then
    echo "Usage: ./tester.sh <nombre_de_tests>"
    exit 1
fi

NUM_TESTS=$1
OK_COUNT=0
KO_COUNT=0
KO_FILE="ko_tests.txt"

for ((i=1; i<=NUM_TESTS; i++))
do
    numbers=$(shuf -i 1-10000 -n 100 | tr '\n' ' ')
    ARG="$numbers"
    result=$(./push_swap $ARG)
    check=$(echo "$result" | ./checker_linux $ARG)

    if [ "$check" == "OK" ]; then
        OK_COUNT=$((OK_COUNT + 1))
    else
        KO_COUNT=$((KO_COUNT + 1))
        echo "Test $i: KO" >> $KO_FILE
        echo "$numbers" >> $KO_FILE
    fi
done

if [ $KO_COUNT -eq 0 ]; then
    echo -e "${GREEN}Tous les tests sont OK: $OK_COUNT${NC}"
else
    echo -e "${RED}Nombre de tests OK: $OK_COUNT${NC}"
    echo -e "${RED}Nombre de tests KO: $KO_COUNT${NC}"
    echo -e "${RED}Voir $KO_FILE pour plus de détails.${NC}"
fi

