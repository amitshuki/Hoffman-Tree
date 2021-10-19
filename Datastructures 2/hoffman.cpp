#include "hoffman.h"
using namespace std;


TreeNode* hoffman::huffman(heap* pq) {
	TreeNode* node = new TreeNode();
	int size = pq->size();
	for (int i = 1; i < size; i++) {
		node = new TreeNode();
		node->SetLeft((pq->deletemin()));//the the first minimum
		node->SetRight((pq->deletemin()));//take the secoend minimum
		node->setFrequency(node->Left()->Frequency() + node->Right()->Frequency());//combain ther frequensy in to anood
		pq->insert(node);
	}

	return pq->deletemin();

}

void hoffman::buildHuffmanTree(string fname) {
	int num;
	string path;
	BStree* t = textToBStree(fname);
	heap* pq = new heap(t);
	BStree a(huffman(pq));
	cout << "Character encoding:" << endl;
	num = printHuffman(path, a.getroot());
	cout << "Encoded file weight: " << num << " bits";
}
BStree* hoffman::textToBStree(string fname) {
	BStree* t = new BStree;
	char c;
	int tempsize;

	ifstream infile;
	infile.open(fname);
	if (!infile) {
		cout << "Error with infile" << endl;
		exit(-1);
	}

	infile.get(c);

	while (!infile.eof()) {
		t->insert(c);
		infile.get(c);
	}
	infile.close();


	return t;
}
int hoffman::printHuffman(string path, TreeNode* root)
{
	int weight = 0;
	if (root == nullptr)
		return -1;
	if (root->isLeaf())
	{
		if (root->letter() == '\n')
			cout << "'\\n' - " << path << endl;
		else {
			if (path.length() == 0) {
				path = "1";
			}
			cout << "'" << root->letter() << "' - " << path << endl;
		}
		weight = (root->Frequency() * path.length());
	}
	else {
		if (root->Left())
			weight = weight + printHuffman(path + "0", root->Left());
		if (root->Right())
			weight = weight + printHuffman(path + "1", root->Right());
	}

	return weight;
}
