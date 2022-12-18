import matplotlib.pyplot as plt
import csv


with open('dataQS.csv', 'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    x = []
    y = []
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

with open('dataPQ.csv', 'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    x2 = []
    y2 = []
    for row in plots:
        x2.append(int(row[0]))
        y2.append(float(row[1]))


# affichage du graphique
plt.plot(x,y, label='QuickSort', color='red')
plt.plot(x2,y2, label='PriorityQueue', color='blue')
plt.xlabel('Taille du tableau')
plt.ylabel('Temps d\'execution en ms')
plt.title('Comparaison des temps d\'execution')
plt.legend()
plt.show()