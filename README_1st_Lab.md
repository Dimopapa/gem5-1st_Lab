# Αρχιτεκτονική Υπολογιστών 1ο εργαστήριο - Αναφορά
#### Ομάδα 36
#### Παπασπανόπουλος Δημοσθένης 8729
#### Φρατζέσκος Παναγιώτης 8939

## Ερωτήματα 

### 1. Εντός της main() στο αρχείο starter_se.py βλέπουμε τα εξής χαρακτηριστηκά:
* CPU type (by default) : atomic
* CPU frequency (by default) : 4 Ghz
* CPU Cores (by default) : 1 core
* Memory type (by default) : DDR3_1600_8x8
* Memory channels (by default) : 2 
* Memory Ranks (by default) : 2
* Memory Size (by default) : 2 GB
* Cache line size : 64

### 2. Εντός του αρχείου config.ini παρατηρούμε : 
* type=MinorCPU          (system.cpu_cluster.cpus)
* numThreads=1           (system.cpu_cluster.cpus)
* ranks_per_channel=2     (system.mem.ctrls0)
* cache_line_size = 64    (system)
* voltage=3.3
* p_state_clk_gate_max=1000000000000

### 3.  
<pre>
Pipeline Stages: Το κάθε Pipeline Stage είναι υπεύθυνο για πράξεις όπως αποκωδικοποίηση ή εκτέλεση κάποιας εντολής, και ανάλογα, είτε
στέλνει οδηγίες στο επόμενο stage εάν η λειτουργία του ήταν επιτυχής και το επόμενο στάδιο είναι έτοιμο να δεχθεί εντολές, είτε κρατάει
την πληροφορία περιμένοντας μέχρι να τηρούνται οι παραπάνω προϋποθέσεις. Τα stages επικοινωνούν μεταξύ τους για 3 λόγους. Όταν στέλνουν
"οδηγίες" στα επόμενα στάδια. Όταν υπάρχει κάποιο πρόβλημα στη ροή, ώστε να σταματήσουν τη ροή της πληροφορίας τα προηγούμενα στάδια.
Τέλος όταν έχει γίνει κάποιο λάθος στην αλληλουχία των σταδίων. 
Συνήθως τα στάδια χρησιμοποιούνται σε πεντάδες με τις εξής λειτουργίες:
 εισαγωγή εντολής
 αποκωδικοποίηση εντολής
 εκτέλεση εντολής, επεξεργασία μνήμης
 εγγραφή καταχωρητών
Resource Request Model: Σε αυτό το μοντέλο, τα resources αναφέρονται σε οποιοδήποτε μέρος του επεξεργαστή θέλουμε μια οδηγία να έχει
πρόσβαση, όπως για παράδειγμα η πρόβλεψη κλάδου, μια μνήμη cache, κάποιος ενεργοποιητής κλπ. Το μοντέλο αυτό, όλα τα εξαρτήματα
θεωρούνται να ανήκουν στη γενική κλάση resources με διαφορετικές, όμως, ιδιότητες. Σε κάθε στάδιο, μια οδηγία ζητείται από το αντίστοιχο
resource. Εάν η εκτέλεση της γίνει με σωστό τρόπο, τότε μεταβαίνει στο επόμενο στάδιο. Για κάθε resource υπάρχουν 2 βασικά
χαρακτηριστικά, η διεύθυνση του και η εντολή που εκτελεί. Μετά από κάθε δημιουργία ενός resource-request, αυτό μεταβαίνει στο Resource
Pool, το οποίο προωθεί την πληροφορία στο κατάλληλο Resource. Κάθε Resource, μόλις λάβει εντολή, ελέγχει εάν μπορεί να την
πραγματοποιήσει εκείνη τη στιγμή κι εάν είναι εφικτό, τότε δεσμεύει τον απαραίτητο χώρο που χρειάζεται και πραγματοποιεί την εργασία,
στέλνοντας επιτυχές σήμα. Εάν για κάποιο λόγο η εργασία δεν εκτελεστεί με επιτυχία, τότε επιστρέφει ανεπιτυχές σήμα.
</pre>


Παρακάτω φαίνεται το πρόγραμμα που έγινε compile.

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

Ίδιος χρόνος - περισσότερα ticks.

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

Ίδιος χρόνος - περισσότερα ticks και σε αυτή την περίπτωση.

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

Είναι προφανές πως ο χρόνος αλλά και τα ticks είναι πολύ μεγαλύτερα και αυτό είναι λογικό γιατί μειώθηκε το ρολόι.

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


*Resources:*

http://gem5.org/Running_gem5
http://learning.gem5.org/book/part1/example_configs.html
http://www.gem5.org/InOrder_Pipeline_Stages
http://www.gem5.org/InOrder_Resource-Request_Model
http://www.gem5.org/docs/html/minor.html
http://www.m5sim.org/SimpleCPU

#### Κριτική

Σαν αντικείμενο είναι αρκετά ενδιαφέρον, ωστόσο έχω κάποια παράπονα όσον αφορά την διαδικασία διότι θεωρώ οτι δεν δόθηκαν πολύ καλά tutorials και αρκέτα κομμάτια ήταν δύσκολο προς κατανόηση. Χρειάστηκαν αρκετές οδηγίες απο το ίντερνετ και παρόλο που θεωρείται εύκολο το πρώτο εργαστήριο δυσκολεύτηκα αρκετά με το περιβάλλον (ειδικά μεχρι να μπορέσω να καταφέρω να βρω υπολογιστή που να μπορεί να τρέξει το πρόγραμμα). Σίγουρα μπορεί να φταίει που είμαι *μόνος* μου στην ομάδα αρα ο φόρτος εργασίας είναι διπλάσιος. Συγνώμη για την κακή κριτική απλώς θεωρώ πως υπάρχουν περιθώρια βελτίωσης και ως προς το υλικό αλλά και ως προς την διαδικασία της προετοιμασίας.
_(Η παραπάνω κριτική είναι προσωπική άποψη - Παπασπανόπουλος Δημοσθένης)_
