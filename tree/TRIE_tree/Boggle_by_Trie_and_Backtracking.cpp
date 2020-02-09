/// Resource 01: https://www.youtube.com/watch?v=T0z1VFXegQk&list=PLjhq5EHRYAeJc6-oMw43yxY6LtieTNV9a&index=6
/// Resource 02: https://www.geeksforgeeks.org/boggle-find-possible-words-board-characters/
/// Resource 03: https://www.geeksforgeeks.org/boggle-set-2-using-trie/
/// problem statement : Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character.
///                     Find all possible words that can be formed by a sequence of 8 adjacent characters without repeat.
/// this code work for only cappital letters. 
/// its an optimized implimentation with trie tree. which will check just the dictionary words.

#include<bits/stdc++.h>
using namespace std;
int Dict_Size, board_row, board_col, visited[21][21];
string Dictionary[21];
char board[21][21];
map<string, int>m;  /// to avoid repeat. 

struct node
{
    bool full;
    node *next[26];
    node() 
    {
        for (int i = 0; i < 26; i++)
        {
            full = false;
            next[i] = NULL;
        }
    }
};

void insert(node* root, string s)
{
    node* curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        int id = s[i] - 'A';
        if (curr->next[id] == NULL) /// only for capital letters.
            curr->next[id] = new node;

        curr = curr->next[id];
    }
    curr->full = true;
}


int drow[] = {0, 0, 1, 1, -1, 1, -1, -1};
int dcol[] = {1, -1, -1, 1, 1, 0, 0, -1};

bool isSafe(int newrow, int newcol, node* curr)
{
    if (newrow >= 0 && newrow < board_row && newcol >= 0 && newcol < board_col && !visited[newrow][newcol] && curr->next[board[newrow][newcol] - 'A'] != NULL)
        return true;
    else
        return false;
}

void BOGGLE_util(int row, int col, string created, node* curr)
{
    if (curr->full && !m.count(created))
    {
        m[created] = 1;        /// to avoid repeat.
        cout << created << endl;
        return;
    }

    if (created.size() == board_row * board_col)
        return;

    for (int i = 0; i < 8; i++)
    {
        int newrow = row + drow[i];
        int newcol = col + dcol[i];
        if (isSafe(newrow, newcol, curr))
        {
            visited[newrow][newcol] = 1;
            BOGGLE_util(newrow, newcol, created + board[newrow][newcol], curr->next[board[newrow][newcol] - 'A']);
            visited[newrow][newcol] = 0;     /// backtrack.
        }
    }
}

void BOGGLE(node* root)
{
    string created = "";
    node* curr = root;
    for (int row = 0; row < board_row; row++)
        for (int col = 0; col < board_col; col++)
        {
            if (curr->next[board[row][col] - 'A'] != NULL) 
            {
                visited[row][col] = 1;
                BOGGLE_util(row, col, created + board[row][col], curr->next[board[row][col] - 'A']);
                visited[row][col] = 0;     /// backtrack.
            }
        }
}

int main()
{
    cout << "No. of entries in dictionary : ";
    cin >> Dict_Size;
    cout << "Entries of Dictionary : ";
    node* root = new node();
    for (int i = 0; i < Dict_Size; i++)
    {
        cin >> Dictionary[i];
        insert(root, Dictionary[i]);
    }

    cout << "Enter the Board row & column : ";
    cin >> board_row >> board_col;

    cout << "Enter the board :" << endl;
    for (int i = 0; i < board_row; i++)
        for (int j = 0; j < board_col; j++)
            cin >> board[i][j];

    cout <<endl<< "The valid words are :" << endl;
    BOGGLE(root);

    return 0;
}

/*
INPUT 01:
No. of entries in dictionary : 5
Entries of Dictionary : GEEKS QUIZ FOR GO SEEK
Enter the Board row & column : 3 3
Enter the board :
G I Z
U E K
Q S E

The valid words are :
GEEKS
QUIZ
SEEK

[note: there two way we can make SEEK. thats why an hashing for valid words is used to avoid repeat.]

*/