#include "priorityQueue.h"
#include <string>
#include <vector>
#include <map>

std::vector<std::pair<char, double>> countFrequency(std::string sample) {
	std::vector<double> freq(128, 0.0);
	int len = sample.length();
	for (int i = 0; i < len; i++) {
		freq[sample[i]]++;
	}
	std::vector<std::pair<char, double>> lettFreq;
	for (int i = 0; i < 128; i++) {
		if (freq[i]) {
			lettFreq.push_back(std::make_pair(char(i), freq[i] / len));
		}
	}
	return lettFreq;
}


TreeNode<std::pair<char, double>>* huffman(std::vector<std::pair<char, double>> lettFreq) {
	PriorityQueue pQ;
	for (auto const& p : lettFreq) {
		TreeNode<std::pair<char, double>>* tNode = new TreeNode<std::pair<char, double>>(std::make_pair(p.first,-p.second));
		pQ.push(tNode);
	}

	while (pQ.getCount() > 1)
	{
		TreeNode<std::pair<char, double>> *t1, *t2;
		t1 = pQ.pop();
		t2 = pQ.pop();
		double freqSum = t1->getVal().second + t2->getVal().second;
		TreeNode<std::pair<char, double>>* t3 = new TreeNode<std::pair<char,double>>(std::make_pair('*', freqSum), t1, t2);
		pQ.push(t3);
	}
	return pQ.peek();
}

void depthTraversal(TreeNode<std::pair<char,double>>* node,std::string code,std::map<char,std::string>& codes) {
	if (node->getLeft() == nullptr && node->getRight() == nullptr) {
		codes.insert(std::make_pair(node->getVal().first, code));
	}
	else {
		if (node->getLeft()) {
			depthTraversal(node->getLeft(), code + "0", codes);
		}
		if (node->getRight()) {
			depthTraversal(node->getRight(), code + "1", codes);
		}
	}
}

std::map<char, std::string> getEncodeMap(TreeNode<std::pair<char, double>>* hTree) {
	std::map<char, std::string> dictionary;
	depthTraversal(hTree,"",dictionary);
	return dictionary;
}

std::string encode(std::string message, std::map<char, std::string> dictionary) {
	std::string code;
	for (char c : message) {
		code += dictionary[c];
	}
	return code;
}

std::string decode(std::string code, TreeNode<std::pair<char, double>>* hTree) {
	TreeNode<std::pair<char, double>>* temp = hTree;
	std::string decoded;
	int i = 0;
	while( i < code.length()) {
		temp = hTree;
		while (temp->getLeft() || temp->getRight())
		{
			if (code[i] == '0') {
				temp = temp->getLeft();
			}
			if (code[i] == '1') {
				temp = temp->getRight();
			}
			i++;
		}
		decoded += temp->getVal().first;
	}
	return decoded;
}


int main() {
	std::string sample = "Exorcizamus te, omnis immundus spiritus  omnis satanica potestas, omnis incursio infernalis adversarii, omnis legio, omnis congregatio et secta diabolica.";
	std::vector<std::pair<char, double>> lettFreq = countFrequency(sample);
	TreeNode<std::pair<char, double>>*  hTree = huffman(lettFreq);
	auto dictionary = getEncodeMap(hTree);

	for (auto m : dictionary) {
		std::cout << m.first << " = " << m.second << std::endl;
	}
	std::cout << encode(sample, dictionary) << std::endl;
	std::cout << decode(encode(sample, dictionary),hTree) << std::endl;

	return 0;
}