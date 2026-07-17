#!/bin/bash

# Create employees.txt

cat > employees.txt << EOF
Alice,Engineering,50,40
Bob,Marketing,35,38
Charlie,Engineering,60,45
David,HR,30,40
Eva,Engineering,55,35
EOF

echo "-----Task 1-----"
awk -F, '{print $1, $2}' employees.txt

echo

echo "-----Task 2-----"
awk -F, '$2=="Engineering"' employees.txt

echo

echo "-----Task 3-----"
awk -F, '{printf "%s gross pay: $%d\n", $1, $3*$4}' employees.txt

echo

echo "-----Task 4-----"
awk -F, '{printf "%d (%d fields): %s\n", NR, NF, $0}' employees.txt

echo

echo "-----Task 5-----"
awk -F, '
BEGIN {
    total = 0
}
$2=="Engineering" {
    total += $3 * $4
}
END {
    printf "Total Engineering Payroll: $%d\n", total
}' employees.txt
