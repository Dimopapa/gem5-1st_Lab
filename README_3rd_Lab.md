# Αρχιτεκτονική Υπολογιστών 2ο εργαστήριο - Αναφορά
### Ομάδα 36
#### Παπασπανόπουλος Δημοσθένης 8729
#### Φρατζέσκος Παναγιώτης 8939

## Ερωτήματα 

### Εξοικείωση με τον εξομοιωτή McPAT
### 1.1 Διαφορές dynamic power και leakage

<pre>Υπάρχουν διάφοροι παράγοντες που συμβάλλουν στην κατανάλωση ισχύος της CPU. Αυτοί είναι οι εξής: 
dynamic power consumption , short-circuit power consumption και power loss λόγω ρευμάτων διαρροής των τρανζίστορ.

Pcpu = Pdyn + Psc + Pleak

Dynamic power consumption προέρχεται από τη δραστηριότητα των λογικών πύλων μέσα σε μια CPU. Όταν οι λογικές πύλες στρέφονται,
η ενέργεια ρέει καθώς οι πυκνωτές μέσα τους φορτίζονται και εκφορτίζονται. Η δυναμική ισχύς που καταναλώνεται από μια CPU είναι
περίπου ανάλογη της συχνότητας της CPU και του τετραγώνου της τάσης της CPU

Pdyn = C*V^2*f
όπου C είναι χωρητικότητα, f είναι συχνότητα, και V είναι τάση.

Leakage Power είναι η στατική ισχύς που καταναλώνεται από τους επεξεργαστές. Εξακολουθεί να καταναλώνεται είτε ο επεξεργαστής εκτελεί ένα
πρόγραμμα είτε απλώς κάνει stall. Προκαλείται λόγω του γεγονότος ότι τα τρανζίστορ έχουν μερικές ατέλειες στο σώμα τους που αφήνουν
το ρεύμα να ρέει μέσα από αυτά (είτε gate  είτε drain-source ή substrate). Τα διάφορα ρεύματα διαρροής είναι:
Subthreshold Ρεύμα, το οποίο είναι το ρεύμα που ρέει μέσω του Source Drain όταν ένα τρανζίστορ υποτίθεται ότι είναι "OFF".
Gate Leakage Ρεύμα, το οποίο είναι το ρεύμα που ρέει μέσω Gate-Substrate λόγω του οξειδίου το οποίο το καθιστά ενεργό ως διηλεκτρικό.
Diode Reverse Ρεύμα, το οποίο ρέει Drain-Substrate ή Source-Substrate λόγω του γεγονότος ότι των αντίθετων φορτίων.
Gate induced Ρεύμα, το οποίο ρέει μέσω Gate-Drain λόγω κατασκευαστικών περιορισμών.

Επιπλέον, υπάρχει μια μεταβλητή στα αποτελέσματα, η Runtime Dynamic. Αυτή η μεταβλητή είναι στην πραγματικότητα η συνολική ενέργεια 
που απαιτείται από ένα πρόγραμμα κατά τη διάρκεια της επεξεργασίας διαιρούμενη με το συνολικό χρόνο προσομοίωσης. Έτσι αν αποφασίσαμε 
να τρέξουμε το ίδιο πρόγραμμα 2 ή περισσότερες φορές διαδοχικά και υποθέτουμε ότι κάθε φορά που ο επεξεργαστής συμπεριφέρεται ακριβώς 
όπως και ο προηγούμενος τότε θα δούμε τα παρακάτω αποτελέσματα:

Το Peak Dynamic θα ήταν το ίδιο με το τρέξιμο του προγράμματος αν το εκτελούσαμε μόνο μία φορά, επειδή ο μέγιστος αριθμός μεταγωγής τρανζίστορ θα
παρέμενε ο ίδιος κατά τη διάρκεια των διαφορετικών εκτελέσεων του προγράμματος.
Το Dynamic Runtime θα ήταν το ίδιο με το τρέξιμο του προγράμματος αν το εκτελούσαμε μόνο μία φορά επειδή θεωρητικά κάθε φορά που ο επεξεργαστής θα
έκανε τους ίδιους υπολογισμούς με τα ίδια τρανζίστορ, έτσι ώστε η απαιτούμενη ενέργεια να είναι η ίδια και ο χρόνος εκτέλεσης θα ήταν ο ίδιος.
Η Total Leakage θα είναι διαφορετική, με την τιμή να είναι n φορές υψηλότερη όπου n είναι ο αριθμός των φορών που τρέχουμε το πρόγραμμα. </pre>

### 1.2 Δύο διαφορετικοί υπολογιστές 5Watt & 40Watt
<pre>Ναι υπάρχει περίπτωση ο δεύτερος επεξεργαστής να δίνει στο σύστημα μεγαλύτερη διάρκεια μπαταρίας βελτιώνοντας το energy efficiency του
Για να το πετύχουμε αυτό θα μπορούσαμε να μειώσουμε τη συχνότητα και την τάση με τρόπο που θα βελτίωνε το energy efficiency του επεξεργαστή χωρίς 
να επηρεάζεται η απόδοσή του.
energy efficiency = performance / Watt
όπου το prefomance ορίζεται ως instructions per second

Παρόλο που ο McPAT μας δίνει όλες τις κατάλληλες πληροφορίες σχετικά με το power, δεν μας δίνει το συνολικό χρόνο προσομοίωσης
που είναι απαραίτητο για τον υπολογισμό της απόδοσης ενός συγκεκριμένου επεξεργαστή. Αυτές οι πληροφορίες θα μπορούσαν να βρεθούν
και να χρησιμοποιηθούν σε μια συνεργασία gem5 + McPat.
energy=(dynamic+leakage)*seconds
</pre>


### 1.3 Xeon vs ARM Cortex-A9 

Προσομοιώνοντας τους 2 αυτούς επεξεργαστές με τις κατάλληλες εντολές βγάζουμε τα παρακάτω αποτελέσματα.

__Xeon__
<pre>
Processor: 
  Area = 410.507 mm^2
  Peak Power = 134.938 W
  Total Leakage = 36.8319 W
  Peak Dynamic = 98.1063 W
  Subthreshold Leakage = 35.1632 W
  Subthreshold Leakage with power gating = 16.3977 W
  Gate Leakage = 1.66871 W
  Runtime Dynamic = 72.9199 W

  Total Cores: 2 cores 
  Device Type= ITRS high performance device type
    Area = 111.713 mm^2
    Peak Dynamic = 78.5978 W
    Subthreshold Leakage = 24.1131 W
    Subthreshold Leakage with power gating = 10.3006 W
    Gate Leakage = 1.49026 W
    Runtime Dynamic = 55.7891 W

  Total L3s: 
  Device Type= ITRS high performance device type
    Area = 293.281 mm^2
    Peak Dynamic = 6.70159 W
    Subthreshold Leakage = 10.9824 W
    Subthreshold Leakage with power gating = 6.06659 W
    Gate Leakage = 0.165767 W
    Runtime Dynamic = 4.32382 W

  Total NoCs (Network/Bus): 
  Device Type= ITRS high performance device type
    Area = 5.51364 mm^2
    Peak Dynamic = 12.807 W
    Subthreshold Leakage = 0.0678232 W
    Subthreshold Leakage with power gating = 0.0305204 W
    Gate Leakage = 0.0126787 W
    Runtime Dynamic = 12.807 W
    </pre>
    

__ARM Cortex-A9__
<pre>
Processor: 
  Area = 5.39698 mm^2
  Peak Power = 1.74189 W
  Total Leakage = 0.108687 W
  Peak Dynamic = 1.6332 W
  Subthreshold Leakage = 0.0523094 W
  Gate Leakage = 0.0563774 W
  Runtime Dynamic = 2.96053 W

  Total Cores: 2 cores 
  Device Type= ITRS low operating power device type
    Area = 4.84735 mm^2
    Peak Dynamic = 1.57159 W
    Subthreshold Leakage = 0.0484486 W
    Gate Leakage = 0.0501375 W
    Runtime Dynamic = 1.06575 W

  Total First Level Directory: 
  Device Type= ITRS low operating power device type
    Area = 0.535391 mm^2
    Peak Dynamic = 0.045212 W
    Subthreshold Leakage = 0.00370577 W
    Gate Leakage = 0.0060234 W
    Runtime Dynamic = 1.81276 W

  Total NoCs (Network/Bus): 
  Device Type= ITRS low operating power device type
    Area = 0.014239 mm^2
    Peak Dynamic = 0.0164048 W
    Subthreshold Leakage = 0.000155022 W
    Gate Leakage = 0.000216526 W
    Runtime Dynamic = 0.0820239 W

</pre>


