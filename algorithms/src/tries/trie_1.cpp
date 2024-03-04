#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#define NUM_CHARS 256

typedef struct trienode {
  struct trienode *children[NUM_CHARS];
  bool terminal;
} trienode;

trienode *createnode() {
  trienode *newnode = new trienode();
  for (int i = 0; i < NUM_CHARS; i++) {
    newnode->children[i] = NULL;
  }
  newnode->terminal = false;
  return newnode;
}

bool trieinsert(trienode **root, char *signedtext) {
  if (*root == NULL) {
    *root = createnode();
  }

  unsigned char *text = (unsigned char *)signedtext;
  trienode *tmp = *root;
  int length = strlen(signedtext);
  for (int i = 0; i < length; i++) {
    tmp->children[text[i]] = createnode();
    tmp = tmp->children[text[i]];
  }
  tmp->terminal = true;
}

bool search(trienode *root, std::string k) {
  auto tmp = root;
  for (int i = 0; i < k.size(); i++) {
    int index = k[i] - 'a';
    if (!tmp->children[index])
      return false;
    tmp = tmp->children[index];
  }
  return (tmp->terminal);
}
