from hashlib import sha256

class Brain:
    def __init__(self, neurons):
        self.neurons = neurons
        self.thought_size = 10

    def brainstem(self):
        return sha256(",".join(str(x) for x in sum(self.neurons, [])).encode()).hexdigest()

    def rot(self, data):
        for i in range(len(data)):
            self.neurons[(3 * i + 7) % self.thought_size][(9 * i + 3) % self.thought_size] ^= data[i]

    def think(self, data):
        thought = [0] * self.thought_size
        for i in range(self.thought_size):
            thought[i] = sum(self.neurons[i][j] * data[j] for j in range(self.thought_size))
        self.neurons[:-1] = self.neurons[1:]
        self.neurons[-1] = thought
        return thought



