#/usr/bin/bash
python gen_test.py

echo "Timing for Strassen:"
time (cat testcase.txt | ./strassen >> /dev/null)

echo "Timing for Normal Matrix Multiply:"
time (cat testcase.txt | ./matrix >> /dev/null)
