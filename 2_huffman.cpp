#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct MinHeapNode{
	char data;
	int freq;

	MinHeapNode *left, *right;

	MinHeapNode(char data, int freq){
		left = right = nullptr;

		this->data = data;
		this->freq = freq;
	}
};

struct compare{
	bool operator()(MinHeapNode *a, MinHeapNode *b){
		return(a->freq > b->freq);
	}
};

void printCodes(struct MinHeapNode *root, string str){
	if(root == nullptr){
		return;
	}

	if(root->data != '$'){
		cout<<root->data<<" : "<<str<<endl;
	}

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}


void HuffmanCode(char data[], int freq[], int size){
	struct MinHeapNode *left, *right, *temp;

	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for(int i= 0; i<size; i++){
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	}

	while(minHeap.size() != 1){
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		temp = new MinHeapNode('$', left->freq + right->freq);
		temp->left = left;
		temp->right = right;
		minHeap.push(temp);
	}

	printCodes(minHeap.top(), "");
}


int main(){
	//predefined inputs
	// char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    // int freq[] = { 5, 9, 12, 13, 16, 45};

	//taking input from the user for the number of elements to be included in the array
	int n;
	cout<<"Enter the number of data/freq array elements:";
	cin>>n;

	//declaring data and frequency arrays
	char data[n];
	int freq[n];

	//taking input for the data array
	cout<<"Enter the data elements:"<<endl;
	for(int i=0; i<n;i++){
		cin>>data[i];
	}
	cout<<endl;

	//taking input for frequency array
	cout<<"Enter the frequency elements:"<<endl;
	for(int i=0; i<n; i++){
		cin>>freq[i];
	}
	cout<<endl;
	HuffmanCode(data, freq, n);
}

// data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
// freq[] = { 5, 9, 12, 13, 16, 45};

// when taken above arrays as input the following will be the output
//f: 0
// c: 100
// d: 101
// a: 1100
// b: 1101
// e: 111

//above i/p and o/p values from gfg