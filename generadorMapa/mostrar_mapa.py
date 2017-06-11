import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
H = np.loadtxt("mapa.map")
cmap = ListedColormap(['saddlebrown','lightgreen','snow','deepskyblue','darkolivegreen','orangered','black','dimgray'])
plt.pcolor(H,cmap=cmap, edgecolor='none')
plt.show()

