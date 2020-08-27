#encoding=utf8

"""
Example of how to use Proxima Python SDK
"""

from pyproxima2 import *
import numpy as np

class Example:
	def __init__(self):
		self.docs = 10
		self.dim = 64
	def prepare_data(self):
		"""
		Insert data into holder
		"""
		self.holder = IndexHolder(type=IndexMeta.FT_FP32, dimension=self.dim)
		for i in range(10000):
			vec = np.random.uniform(low=0.0, high=1.0, size=64).astype('f')
			self.holder.emplace(i, vec)

	def build(self):
		"""
		Build index
		"""
		builder = IndexBuilder(
				name="ExampleBuilder",
				meta=IndexMeta(type=IndexMeta.FT_FP32, dimension=self.dim),
				params={'proxima.hc.builder.max_document_count': self.docs}
				)

		builder.build(self.holder)
		# ...
	
	def search(self):
		"""
		Search
		"""
		searcher = IndexSearcher("ExampleSearcher")
		# init container
		container = IndexContainer(name='FileContainer',
                                   path="index/example.index",
                                   params={})

		# load index
		searcher.load(container)

		# create search context
		# ctx = searcher.create_context(topk=10)

		# do search
		# vec = np.random.uniform(low=0.0, high=1.0, size=64).astype('f')
		# results = ctx.search(query=vec)
		# for ele in results[0]:
		#	print("Result: the key is: {0}\tscore is: {1}.".format(ele.key(), ele.score()))
		# ... 

def main():
	# IndexPlugin.load("<path to your .so file>")
    IndexPlugin.load("./../build/libtianchi_example.so")
    exp = Example()
    exp.prepare_data()
    exp.build()
    exp.search()

if __name__=='__main__':
	main()
