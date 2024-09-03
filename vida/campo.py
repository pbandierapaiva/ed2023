# Campo para simulação

import matplotlib.pyplot as plt
import numpy as np

class Campo:
    def __init__(self, ptam=100):
        self.tam = ptam
        self.vidas = []
        self.grade = np.zeros( (self.tam,self.tam), dtype=int )
    def preenchegrade(self):
        self.grade = np.zeros( (self.tam,self.tam), dtype=int )
        for vida in self.vidas:
            self.seta(vida.x,vida.y)
    def mostra(self):
        plt.imshow(self.grade, cmap='binary')
        plt.xticks([]), plt.yticks([])  # Hide the tick labels
        plt.show()
    def cria(self,direcoes=0b1111, posX=-1,posY=-1):
        if len(self.vidas) >= self.tam*self.tam:
            raise OverflowError("Não cabem mais vidas nesse Campo")
        
        if(posX==-1 or posY==-1):
            posX,posY = self.sorteiaVaga()
        if self.estado(posX,posY)!=0:
            return False
        criatura = Ser(self,direcoes,posX,posY)
        self.grade[posX][posY] = 1
        self.vidas.append(criatura)
    def criaVarios(self, n=1):
        for i in range(n):
            self.cria()
    def sorteiaVaga(self):
        while(True):
            tx = int(np.random.rand()*self.tam)
            ty = int(np.random.rand()*self.tam)
            if self.estado(tx,ty)==0:  # está livre!
                return (tx,ty)

    def estado(self, x, y):
        return self.grade[x][y]
    def zera(self, l, c):
        self.grade[l][c]=0
    def seta(self, l, c):
        self.grade[l][c]=1
    def tique(self, n=1):
        for t in range(n):
            for vida in self.vidas:
                vida.anda()
    def dizimarBaixos(self, limite):
        for i in self.vidas:
            if i.y>limite:
                self.zera(i.x,i.y)
                del self.vidas[ self.vidas.index(i) ]

class Ser:
    def __init__(self, pCampo, pDirecoes, posX, posY):
        self.campo = pCampo
        self.x = posX
        self.y = posY
        # sorteia mutação
        if int(np.random.rand()*100)<5:  # 5% mutam
            bit = int(np.random.rand()*4) # bit será 0,1,2 ou 3
            if bit==0:
                self.direcoes = pDirecoes ^ 0b1000
            elif bit==1:
                self.direcoes = pDirecoes ^ 0b0100
            elif bit==2:
                self.direcoes = pDirecoes ^ 0b0010
            elif bit==3:
                self.direcoes = pDirecoes ^ 0b0001
        else:
            self.direcoes = pDirecoes  # binário: cima, baixo, direita, esquerda
    def __repr__(self):
        return "Ser em (%d,%d)"%(self.x,self.y)
    def __str__(self):
        return "(%d,%d)"%(self.x,self.y)
    def anda(self): # perambula um passo para qualquer direção permitida
        direcao = int(np.random.rand()*4) # 0-cima,1-baixo,2-direita,3-esquerda
        if   direcao==0 and self.direcoes & 0b1000:  # cima
            self.vaipara(self.x,self.y-1)
        elif direcao==1  and self.direcoes & 0b0100: # baixa
            self.vaipara(self.x,self.y+1)
        elif direcao==2  and self.direcoes & 0b0010: # direita
            self.vaipara(self.x+1,self.y)
        elif direcao==3  and self.direcoes & 0b0001: # esquerda
             self.vaipara(self.x-1,self.y)
       
    def vaipara(self,posX,posY):
        if posX>=self.campo.tam or posX<0 or posY>=self.campo.tam or posY<0:
            return False
        if self.campo.estado(posX,posY)==0: # não ocupada
            self.campo.zera(self.x,self.y) #desocupa
            self.campo.seta(posX,posY)    #ocupa
            self.x=posX
            self.y=posY
            return True
        else:
            return False

    def duplica(self):
        self.campo.cria



c = Campo()
# c.mostra()