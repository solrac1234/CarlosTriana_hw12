import numpy as np

import matplotlib.pyplot as plt




SNAPSHOT1= np.loadtxt("advection.txt")[:, 0]

SNAPSHOT2= np.loadtxt("advection.txt")[:, 1]

SNAPSHOT3= np.loadtxt("advection.txt")[:, 2]

SNAPSHOT4 = np.loadtxt("advection.txt")[:, 3]

SNAPSHOT5= np.loadtxt("advection.txt")[:, 4]

x = range(len(SNAPSHOT1))


plt.plot(x, SNAPSHOT1, label="s1")
plt.plot(x, SNAPSHOT2, label="s2")
plt.plot(x, SNAPSHOT3, label="s3")
plt.plot(x, SNAPSHOT4, label="s4")
plt.plot(x, SNAPSHOT5, label="s5")
plt.title("Advection")
plt.ylim(0, 1)
plt.xlabel("eje x")
plt.ylabel("eje y")



plt.savefig("advection.png")
plt.show()

