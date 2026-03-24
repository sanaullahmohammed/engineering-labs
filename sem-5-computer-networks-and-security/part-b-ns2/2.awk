# Author: G. Srinivasachar
# Date: 3/6/16
#
# File 2.awk
# Count dropped packets due to congestion
BEGIN {
count=0;
}
{
if($1=="d") count++;
}
END {
printf("total no of packets dropped due to cngestion : %d\n", count);
}
