#include<iostream>
#include<queue>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c,int f){
        ch = c;
        freq =f;
        left = right = nullptr;
    }
};

struct Compare{
    bool operator()(Node* a, Node* b){
        return a-> freq > b-> freq;
}
};

void printcodes(Node* root, string str){
    if(!root) return;
    if(!root->left && !root->right){
        cout<<root->ch<<": "<<str<<endl;
    }
    printcodes(root->left, str +"0");
    printcodes(root->right, str +"1");
}

void huffman_encoding(vector<char> ch, vector<int> freq, int n){
    priority_queue<Node*,vector<Node*>, Compare> pq;

    for(int i=0;i<n;i++){
        pq.push(new Node(ch[i], freq[i]));
    }

    while(pq.size()>1){

        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop(); 

        Node* parent = new Node('$',left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    Node* rot = pq.top();
    cout << "\nHuffman Codes:\n";
    
    printcodes(rot, "");

}

int main(){
    int n;

    cout<<"Enter the number of characters: ";
    cin>>n;

    vector<char> ch(n);
    vector<int> freq(n);

    cout<<"Enetr the characters and their frequencies: "<<endl;
    for (int i=0;i<n;i++){
        cin>>ch[i]>>freq[i];
    }

    huffman_encoding(ch, freq, n);

    return 0;

}