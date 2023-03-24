Per la compilazione è necessario inserire il path di "pacs-examples" nella variabile PATH_PACSEXAMPLE nel Makefile. In quanto si fa uso del file "basicZeroFun.hpp" e delle librerie da esso utilizzate.
Inoltre è necessaria la libreria "boost" per l'uso di gnuplot.

La classe CauchyProblem definisce un problema di cauchy e fornisce vari metodi per il calcolo delle soluzioni numeriche e per visualizzare e salvare la soluzione.
L'idea della classe è appunto quella di definire un problema di cauchy, per questo motivo non è possibile modificare i parametri che definiscono il problema matematico. E' invece possibile modificare i parametri per il calcolo della soluzione numerica (il numero di passi e theta).
Implementa 4 schemi risolutivi: Eulero in avanti con EFSolution(), Eulero all'indierto con EBSolution(), Crank-Nicolson con CNSolution() e lo schema risolutivo con un generico theta con ThetaSolution(theata). Questi metodi restituiscono la relativa soluzione in un dato del tipo NumSolution aka std::tuple<std::vector<double>, std::vector<double>>, dove il primo vettore contiene gli istanti di tempo dove viene valutata la soluzione e il secondo contiente i corrispondenti valori della soluzione.
Ogni soluzione dei 4 metodi che è calolata viene salvata in un array di soluzioni: "Solutions", in modo da evitare il ricalcolo della soluzione con lo stesso metodo. In particolare per ThetaSolution viene salvata la soluzione per l'ultima theta inserita (non ricolcolata se la theta è invariata).
Il calcolo effettivo della soluzione di tutti 4 i metodi è effettuato da Solver.
E' possibile stampare a schermo con print(), visualizzare un grafico gnuplot con plot() e salvare in un file la soluzione con save(). Questi tre metodi utilizzano come soluzione l'ultima soluzione calcolata, ma è possibile, attraverso il metodo SetTheta(theta), selezionare una soluzione diversa dall'ultima calcolata (o se non è ancora stata calcolata una soluzione, una diversa da quella di default: CN). In generale se la soluzione desiderata non è gia stata calcolata lo viene fatto chiamando il relativo metodo.
Inoltre la classe ha due costruttori:
- CauchyProblem(ODE f, double y0, double t0, double t1) definisce completamente il problema di cauchy
- CauchyProblem(ODE f) richiede solamente l'equazione differenziale da risolvere ed utilizza come parametri di default y0=0, t0 = 0, T = 1.

Solver restituisce una soluzione calcolata con uno schema risoluto a differenze finite con una generica theta.
In particolare per il calcolo dello zero al suo interno è stato utilizzato il metodo della secante implementato di "basicZeroFun.hpp", come punti per il calcolo della derivata sono utilizzati gli estremi dell'intervallo centrato nel precendete risutato u[i-1] e di ampiezza pari a 2*(2*odefun(t[i],u[i-1])+0.01).
