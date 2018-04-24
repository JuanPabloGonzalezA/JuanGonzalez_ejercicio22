import numpy as np
import matplotlib.pyplot as plt

datos=np.loadtxt('datos1.txt')
inicialx=datos[datos[:,0]==0,1]
inicialu=datos[datos[:,0]==0,2]
finalx=datos[datos[:,0]==1,1]
finalu=datos[datos[:,0]==1,2]
plt.plot(inicialx,inicialu,label=r'$t=0$')
plt.plot(finalx,finalu,label=r'$t=\mathrm{final}$')
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x,t)$')
plt.legend()
plt.savefig('grafica1.png')
