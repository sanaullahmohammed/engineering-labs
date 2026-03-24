# File 5.awk
# Wireless LAN link performance
BEGIN {
	packets_sent = 0;
	packets_acks = 0;
}
{
	if($1 == "r" && $5 == "tcp")
	{
		packets_sent++;
	}
	
	if($1 == "r" && $5 == "ack")
	{
		packets_acks++;
	}
}
END {
	printf("Packets sent = %d\n", packets_sent);
	printf("Packets acks = %d\n", packets_acks);
}

