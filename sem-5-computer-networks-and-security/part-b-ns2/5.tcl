# File 5.tcl
# Wireless LAN simulation


set ns [new Simulator]
set tf [open out.tr w]
set nf [open out.nam w]

$ns trace-all $tf
$ns namtrace-all $nf

# create nodes
set node(ms1) [$ns node]
set node(bs1) [$ns node]
set node(msc) [$ns node]
set node(bs2) [$ns node]
set node(ms2) [$ns node]

#create links
$ns duplex-link $node(ms1) $node(bs1) 1Mb 1ms DropTail
$ns duplex-link $node(bs1) $node(msc) 1Mb 10ms DropTail
$ns duplex-link $node(msc) $node(bs2) 1Mb 10ms DropTail
$ns duplex-link $node(bs2) $node(ms2) 1Mb 1ms DropTail

puts "Cell Topology"

#change bandwidth and create simplex links
$ns bandwidth $node(ms1) $node(bs1) 9.6Kb simplex
$ns bandwidth $node(bs1) $node(ms1) 9.6Kb simplex
$ns insert-delayer $node(ms1) $node(bs1) [new Delayer]

#create connection
set tcp [$ns create-connection TCP $node(ms1) TCPSink $node(ms2) 0]
set ftp [$tcp attach-app FTP]

#finish function
proc finish {} {
	global ns tf nf
	$ns flush-trace
	close $tf
	close $nf
	exit 0
}

$ns at 0.1 "$ftp start"
$ns at 20 "finish"
$ns run
#xgraph -P -bar -x TIME -y DATA gsm.xg
