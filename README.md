# gem5-1st_Lab 
## Question 1

### 1. Inside main() of starter_se.py we can see :
* CPU type (by default) : atomic
* CPU frequency (by default) : 4 Ghz
* CPU Cores (by default) : 1 core
* Memory type (by default) : DDRE_1600_8x8
* Memory channels (by default) : 2 
* Memory Ranks (by default) : 2
* Memory Size (by default) : 2 GB
* Cache line size : 64

### 2. Inside config.ini file we can see : 
* type=MinorCPU          (system.cpu_cluster.cpus)
* numThreads=1           (system.cpu_cluster.cpus)
* ranks_per_channel=2     (system.mem.ctrls0)
* cache_line_size = 64    (system)

### 3. I compiled this mini program and the results are: 


<pre>
#include <stdio.h>
int main ()
{
  int i,sum=0;
  printf("\nWe are calculating the sum from 1 to 10\n \n");
  for(i=1; i<=9; i++)
  { 
    sum = sum + i;
  }
  printf("Sum is : %d \n \n", sum) ;
  return 0;
}
</pre>


a) *Using MinorCPU*

<pre>
final_tick                                   36009000                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)
host_inst_rate                                  95646                       # Simulator instruction rate (inst/s)
host_mem_usage                                 711596                       # Number of bytes of host memory used
host_op_rate                                   109656                       # Simulator op (including micro ops) rate (op/s)
host_seconds                                     0.12                       # Real time elapsed on the host
host_tick_rate                              309482460                       # Simulator tick rate (ticks/s)
sim_freq                                 1000000000000                       # Frequency of simulated ticks
sim_insts                                       11113                       # Number of instructions simulated
sim_ops                                         12754                       # Number of ops (including micro ops) simulated
sim_seconds                                  0.000036                       # Number of seconds simulated
sim_ticks                                    36009000                       # Number of ticks simulated
</pre>

*Using TimingSimpleCPU*
<pre>
final_tick                                   41692000                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)
host_inst_rate                                 239950                       # Simulator instruction rate (inst/s)
host_mem_usage                                 707244                       # Number of bytes of host memory used
host_op_rate                                   273493                       # Simulator op (including micro ops) rate (op/s)
host_seconds                                     0.05                       # Real time elapsed on the host
host_tick_rate                              898777443                       # Simulator tick rate (ticks/s)
sim_freq                                 1000000000000                       # Frequency of simulated ticks
sim_insts                                       11049                       # Number of instructions simulated
sim_ops                                         12636                       # Number of ops (including micro ops) simulated
sim_seconds                                  0.000042                       # Number of seconds simulated
sim_ticks                                    41692000                       # Number of ticks simulated
</pre>

b) different CPUs have different times and results
 
c) By specifying sizes for the L1 caches ( --l1d_size=64kB --l1i_size=16kB )

*MinorCPU*
<pre>
final_tick                                   37654000                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)
host_inst_rate                                  96709                       # Simulator instruction rate (inst/s)
host_mem_usage                                 711592                       # Number of bytes of host memory used
host_op_rate                                   110867                       # Simulator op (including micro ops) rate (op/s)
host_seconds                                     0.12                       # Real time elapsed on the host
host_tick_rate                              327195246                       # Simulator tick rate (ticks/s)
sim_freq                                 1000000000000                       # Frequency of simulated ticks
sim_insts                                       11113                       # Number of instructions simulated
sim_ops                                         12754                       # Number of ops (including micro ops) simulated
sim_seconds                                  0.000038                       # Number of seconds simulated
sim_ticks                                    37654000                       # Number of ticks simulated </pre>
we can see that the time now is bigger! 

*TimingSimpleCPU*
<pre>final_tick                                   42582000                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)
host_inst_rate                                 252049                       # Simulator instruction rate (inst/s)
host_mem_usage                                 707244                       # Number of bytes of host memory used
host_op_rate                                   287435                       # Simulator op (including micro ops) rate (op/s)
host_seconds                                     0.04                       # Real time elapsed on the host
host_tick_rate                              967686779                       # Simulator tick rate (ticks/s)
sim_freq                                 1000000000000                       # Frequency of simulated ticks
sim_insts                                       11049                       # Number of instructions simulated
sim_ops                                         12636                       # Number of ops (including micro ops) simulated
sim_seconds                                  0.000043                       # Number of seconds simulated
sim_ticks                                    42582000                       # Number of ticks simulated </pre>
We can see that the time now is bigger too! 

By changing clock to 10000 we had these results 

*MinorCPU*
<pre>final_tick                               1892100000000                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)
host_inst_rate                                   1772                       # Simulator instruction rate (inst/s)
host_mem_usage                                 711596                       # Number of bytes of host memory used
host_op_rate                                     2034                       # Simulator op (including micro ops) rate (op/s)
host_seconds                                     6.27                       # Real time elapsed on the host
host_tick_rate                           301757101652                       # Simulator tick rate (ticks/s)
sim_freq                                 1000000000000                       # Frequency of simulated ticks
sim_insts                                       11113                       # Number of instructions simulated
sim_ops                                         12754                       # Number of ops (including micro ops) simulated
sim_seconds                                  1.892100                       # Number of seconds simulated
sim_ticks                                1892100000000                       # Number of ticks simulated</pre>
really bigger time !

*TimingSimpleCPU*
<pre>final_tick                               3397600000000                       # Number of ticks from beginning of simulation (restored from checkpoints and never reset)
host_inst_rate                                   1016                       # Simulator instruction rate (inst/s)
host_mem_usage                                 707240                       # Number of bytes of host memory used
host_op_rate                                     1161                       # Simulator op (including micro ops) rate (op/s)
host_seconds                                    10.88                       # Real time elapsed on the host
host_tick_rate                           312279780559                       # Simulator tick rate (ticks/s)
sim_freq                                 1000000000000                       # Frequency of simulated ticks
sim_insts                                       11049                       # Number of instructions simulated
sim_ops                                         12636                       # Number of ops (including micro ops) simulated
sim_seconds                                  3.397600                       # Number of seconds simulated
sim_ticks                                3397600000000                       # Number of ticks simulated </pre>



#### Κριτική

Σαν αντικείμενο είναι αρκετά ενδιαφέρον, ωστόσο έχω κάποια παράπονα όσον αφορά την διαδικασία διότι θεωρώ οτι δεν δόθηκαν πολύ καλά tutorials και αρκέτα κομμάτια ήταν δύσκολο προς κατανόηση. Χρειάστηκαν αρκετές οδηγίες απο το ίντερνετ και παρόλο που θεωρείται εύκολο το πρώτο εργαστήριο δυσκολεύτηκα αρκετά με το περιβάλλον (ειδικά μεχρι να μπορέσω να καταφέρω να βρω υπολογιστή που να μπορεί να τρέξει το πρόγραμμα). Σίγουρα μπορεί να φταίει που είμαι *μόνος* μου στην ομάδα αρα ο φόρτος εργασίας είναι διπλάσιος. Συγνώμη για την κακή κριτική απλώς θεωρώ πως υπάρχουν περιθώρια βελτίωσης και ως προς το υλικό αλλά και ως προς την διαδικασία της προετοιμασίας.
