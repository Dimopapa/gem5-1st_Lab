# Αρχιτεκτονική Υπολογιστών 2ο εργαστήριο - Αναφορά
### Ομάδα 36
#### Παπασπανόπουλος Δημοσθένης 8729
#### Φρατζέσκος Παναγιώτης 8939

## Ερωτήματα 

### Εξοικείωση με τον εξομοιωτή McPAT
### 1.1 Διαφορές dynamic power και leakage

Υπάρχουν διάφοροι παράγοντες που συμβάλλουν στην κατανάλωση ισχύος της CPU. Αυτοί είναι οι εξής: 
dynamic power consumption , short-circuit power consumption και power loss λόγω ρευμάτων διαρροής των τρανζίστορ.

Pcpu = Pdyn + Psc + Pleak

Το **Dynamic Power** σχετίζεται με την δραστηριότητα των λογικών πυλών στο εσωτερικό του επεξεργαστή. Οι πυκνωτές του
κυκλώματος φορτίζονται και αποφορτίζονται, ώστε να αλλάζουν κατάσταση οι διακόπτες του. Αποτέλεσμα αυτής της
διαδικασίας είναι η κατανάλωση ισχύος. 
Παράγοντες που επηρεάζουν το dynamic power είναι οι εξής:
i. Συχνότητα  του ρολογιού
ii. Παροχή ηλεκτρικού ρεύματος Vdd
iii. Συνολική Χωρητικότητα των πυκνωτών
iv. Συνελεστής Activity-Factor 
Για τον υπολογισμό της συνολικής χωρητικότητας, το μοντέλο του επεξεργαστή χωρίζεται τμηματικά σε μικρότερα μέρη ώστε
να μπορεί να μελετηθεί καλύτερα και ευκολότερα. Ο υπολογισμός του activity-factor γίνεται χρησιμοποιώντας στατιστικά
δεδομένα που έχουν σχέση με τα Requests-Access του επεξεργαστή, έπειτα από τις απαιτούμενες προσομοιώσεις.

Το **Leakage** έχει να κάνει με την static power που καταναλώνεται από τον επεξεργατή είτε όταν αυτός εκτελεί ένα πρόγραμμα
είτε όταν απλά κάνει stall (είναι δηαλαδή σε κατάσταση αναμονής). Υπάρχουν 2 υποκατηγορίες:
α. subthreshold leakage, συμβαίνει όταν ένα τρανζίστορ το οποίο βρίσκεται σε ανενεργή κατάσταση επιτρέπει την ροή μιας
μικρής ποσότητας ρεύματος. Προφανώς και όταν μιλάμε για έναν πολύ μεγάλο αριθμό από τρανζιστορ της τάξης των
δισεκατομμυρίων αυτή η τιμή είναι αρκετά μεγάλη και σίγουρα όχι αμελητέα.
β. gate leakage προέρχεται από την διαρροή ενός μικρού ρεύματος από την πύλη του κάθε τρανζίστορ και διαφοροποιείται
αρκετά ανάλογα με την κατάσταση του επεξεργαστή.


Επιπλέον, υπάρχει μια μεταβλητή στα αποτελέσματα, η Runtime Dynamic. Αυτή η μεταβλητή είναι στην πραγματικότητα η
συνολική ενέργεια που απαιτείται από ένα πρόγραμμα κατά τη διάρκεια της επεξεργασίας διαιρούμενη με το συνολικό χρόνο
προσομοίωσης. Έτσι αν αποφασίσαμε να τρέξουμε το ίδιο πρόγραμμα 2 ή περισσότερες φορές διαδοχικά και υποθέτουμε ότι 
κάθε φορά που ο επεξεργαστής συμπεριφέρεται ακριβώς όπως και ο προηγούμενος τότε θα δούμε τα παρακάτω αποτελέσματα:

Το Peak Dynamic θα ήταν το ίδιο με την εκτέλεση του προγράμματος αν το εκτελούσαμε μόνο μία φορά, επειδή ο μέγιστος αριθμός των switch
των τρανζίστορ θα παρέμενε ο ίδιος κατά τη διάρκεια των διαφορετικών εκτελέσεων του προγράμματος.

Το Dynamic Runtime θα ήταν το ίδιο με την εκτέλεση του προγράμματος αν το εκτελούσαμε μόνο μία φορά επειδή θεωρητικά κάθε φορά ο 
επεξεργαστής θα έκανε τους ίδιους υπολογισμούς με τα ίδια τρανζίστορ, έτσι η απαιτούμενη ενέργεια να ήταν η ίδια και ο χρόνος εκτέλεσης
θα ήταν ο ίδιος.

Η Total Leakage θα είναι διαφορετική, με την τιμή να είναι n φορές υψηλότερη όπου n είναι ο αριθμός των φορών που τρέχουμε το 
πρόγραμμα. 

### 1.2 Δύο διαφορετικοί υπολογιστές 5Watt & 40Watt
Σύμφωνα με μια σύντομη αναζήτηση μπορούμε να βγάλουμε το συμπέρασμα πως το energy efficiency ορίζεται ως η απόδοση προς την κατανάλωση.
energy efficiency = performance / Watt
όπου το prefomance ορίζεται ως instructions per second
Στο συγκεκριμένο παράδειγμα ο 1ος επεξεργαστής καταναλώνει 5 watt, ενώ ο δεύτερος επεξεργαστής καταναλώνει 40 watt. O επεξεργαστής που
θα κάνει το σύστημα να έχει μεγαλύτερη διάρκεια μπαταρίας είναι αυτός που θα παρουσιάζει και το μεγαλύτερο Energy Efficiency. Σε αυτό
το σημείο φαίνεται ο ρόλος του χρόνου που επηρεάζει σύστημα. Έτσι λοιπόν για να έχει ο 2ος επεξεργαστής μεγαλύτερο Energy-Efficiency,
θα πρέπει να εκτελέσει τις εντολές οχτώ φορές πιο γρήγορα από τον πρώτο, καθώς 5 * 8 = 40. 

Παρόλο που ο McPAT μας δίνει όλες τις κατάλληλες πληροφορίες σχετικά με το power, δεν μας δίνει το συνολικό χρόνο προσομοίωσης
που είναι απαραίτητο για τον υπολογισμό της απόδοσης ενός συγκεκριμένου επεξεργαστή. Αυτές οι πληροφορίες θα μπορούσαν να βρεθούν
και να χρησιμοποιηθούν σε μια συνεργασία gem5 + McPat.




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

Για να υπολογίσουμε το Energy Efficiency κάθε επεξεργαστή, αρκεί να διαιρέσουμε την υπολογιστική ικανότητα του προς το Runtime Dynamic
power. Υποθέτωντας ότι x είναι η υπολογιστική ικανότητα του ARM_A9, η ικανότητα του Xeon θα είναι 40x. Επομένως:

***ARM_A9**: Energy_Efficiency = x / 2.96 = 0.34x
**Xeon**: Energy_Efficiency = 40x / 72.92 = 0.55x*

Με τα παραπάνω δεδομένα παρατηρούμε ότι ο Xeon είναι πιο αποδοτικός από τον ARM. Ωστόσο επειδή αναφέρεται ότι δεν
διακόπτεται η λειτουργία του συστήματος μετά την ολοκλήρωση της εφαρμογής, πρέπει να συμπεριλάβουμε και το Total Leakage. Το Total
Leakage του ARM_A9 είναι 0.1W ενώ του Xeon είναι 36W, δηλαδή περίπου 360 φορές μεγαλύτερο. Δεδομένο αυτού, ο ARM_A9 είναι πολύ πιο
αποδοτικός στην εκτέλεση της εφαρμογής μας.



### 2.1 Υπολογισμός των Energy Delay Area 

Το Delay ουσιαστικά μας δίνεται από την τιμή του total_simulation_seconds του αρχείου stats.txt από τον gem5.

Το Area το παίρνουμε από το αρχείο του McPAT.

To Energy, χρησιμοποιώντας τα scripts που μας δώθηκαν και με την χρήση της εντολής
_print_energy.py mcpat_output_file gem5_stats_file_ μπορούμε να πάρουμε την τιμή του. Αλλιώς μπορόυμε να την υπολογίσουμε από τον τύπο
*energy = (runtime_dynamic+total_leakage) * simulation_time*

### 2.2 Επίδραση των παραμέτρων για Peak Power και Area

Μορφοποιήσαμε καταλλήλως τα scripts συμφωνα με τις οδηγίες και τρέξαμε simulations για το benchmark bzip.
Βλέπουμε παρακάτω τα σχετικά διαγράμματα που προκύπτουν.

**L1 instruction cache size**
![image](https://user-images.githubusercontent.com/43822588/71594839-1e098e00-2b42-11ea-9902-51073941a100.png)

**L1 instruction cache associativity**

![image](https://user-images.githubusercontent.com/43822588/71594979-940df500-2b42-11ea-9fc1-e842c9ec577c.png)

**L1 data cache size**

![image](https://user-images.githubusercontent.com/43822588/71595049-d8999080-2b42-11ea-96be-9ac7aaff32b7.png)

**L1 data cache associativity**

![image](https://user-images.githubusercontent.com/43822588/71595151-30d09280-2b43-11ea-97b4-0abeb42ac283.png)

**L2 cache size**

![image](https://user-images.githubusercontent.com/43822588/71595226-74c39780-2b43-11ea-857d-dbf5a655ca56.png)

**L2 cache associativity**

![image](https://user-images.githubusercontent.com/43822588/71595284-a89ebd00-2b43-11ea-9832-2b1fcb731b29.png)


**cache line size**

![image](https://user-images.githubusercontent.com/43822588/71595361-e8fe3b00-2b43-11ea-84bd-2e44878e18ad.png)


Συμπερασματικά την μεγαλύτερη επιρροή την βλεπουμε στο cache line size , κάτι που το περιμέναμε σύμφωνα και με τις μεταβολές του στο
προηγούμενο εργαστήριο.


