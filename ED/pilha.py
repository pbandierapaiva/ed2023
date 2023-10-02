
class Pilha(list):
	def __init__(self):
		list.__init__(self)
	
	def push(self, ele):
		self.append( ele )
		
	def pop(self):
		if len(self)==0:  # Pilha vazia!
			print("Pilha vazia")
			return
		valor = self[-1]
		del self[-1]
		return valor
	def peek(self):
		return self[-1]
	def isEmpty(self):
		return not(len(self)) 
	def size(self):
		return len(self)
