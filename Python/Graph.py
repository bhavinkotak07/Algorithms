class Vertex:
    def __init__(self, key):
        self.id = key
        self.distance = 0
        self.color = 'white'
        self.predecessor = None
        self.connectedTo = {}
    def addNeighbor(self, nbr, weight):
        self.connectedTo[nbr] = weight
    def __str__(self):
        return str(self.id) + " connected to " + str([i.id for i in self.connectedTo])
    def getConnections(self):
        return self.connectedTo.keys()
    def getId(self):
        return self.id
    def getWeight(self, nbr):
        return self.connectedTo[nbr]
    def setDistance(self, d):
        self.distance = d
    def getDistance(self):
        return self.distance
    def setColor(self, value):
        self.color = value
    def getColor(self):
        return self.color
    def setPred(self, v):
        self.predecessor = v
    def getPred(self):
        return self.predecessor


class Queue:
    def __init__(self):
        self.data = []
    def enqueue(self, key):
        self.data.insert(0, key)
    def dequeue(self):
        return self.data.pop()
    def isEmpty(self):
        return self.data == []
    def size(self):
        return len(self.data)
class Graph:
    def __init__(self):
        self.vertList = {}
        self.numberOfVertices = 0
    def addVertex(self, v):
        self.numberOfVertices += 1
        newVertex = Vertex(v)
        self.vertList[v] = newVertex
        return newVertex
    def getVertex(self, n):
        if n in self.vertList:
            return self.vertList[n]
        else:
            return None
    def __contains(self, n):
        return n in self.vertList
    def addEdge(self, fro , to, cost = 0):
        if fro not in self.vertList:
            self.addVertex(fro)
        if to not in self.vertList:
            self.addVertex(to)
        self.vertList[fro].addNeighbor(self.vertList[to], cost)
    def getVertices(self):
        return self.vertList.keys()

    def __iter__(self):
        return iter(self.vertList.values())




def bfs(g,start):
  start.setDistance(0)
  start.setPred(None)
  vertQueue = Queue()
  vertQueue.enqueue(start)
  while (vertQueue.size() > 0):
    currentVert = vertQueue.dequeue()
    for nbr in currentVert.getConnections():
      if (nbr.getColor() == 'white'):
        nbr.setColor('gray')
        nbr.setDistance(currentVert.getDistance() + 1)
        nbr.setPred(currentVert)
        vertQueue.enqueue(nbr)
    currentVert.setColor('black')
    
