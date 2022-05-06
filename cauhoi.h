int height(NodeCauHoi *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

/* Helper function that allocates a
   new node with the given key and
   nullptr left and right pointers. */
NodeCauHoi *newNode(CauHoi cauHoiMoi)
{
    NodeCauHoi *node = new NodeCauHoi();
    node->info = cauHoiMoi;
    node->key = cauHoiMoi.id;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return (node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
NodeCauHoi *rightRotate(NodeCauHoi *y)
{
    NodeCauHoi *x = y->left;
    NodeCauHoi *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    // Return new root
    return x;
}

NodeCauHoi *leftRotate(NodeCauHoi *x)
{
    NodeCauHoi *y = x->right;
    NodeCauHoi *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(NodeCauHoi *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

bool checkDapAnTrung(string a, string b, string c, string d)
{
    if (a == b || a == c || a == d)
    {
        return false;
    }
    else if (b == c, b == d)
    {
        return false;
    }
    else if (c == d)
    {
        return false;
    }
    return true;
}

NodeCauHoi *themCauHoi(NodeCauHoi *node, int key, CauHoi cauHoiMoi)
{

    if (node == nullptr)
        return (newNode(cauHoiMoi));
    if (key < node->key)
        node->left = themCauHoi(node->left, key, cauHoiMoi);
    else if (key > node->key)
        node->right = themCauHoi(node->right, key, cauHoiMoi);
    else
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int countNodeCauHoi(NodeCauHoi *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + countNodeCauHoi(root->left) + countNodeCauHoi(root->right);
    }
}


void rongMangCauHoi(mangCauHoi &dsCauHoi) {
    for ( int i = 0 ; i < dsCauHoi.tongSoCau; i++) {
        dsCauHoi.arrCauHoiThi[i] = nullptr;
    }
    dsCauHoi.tongSoCau = 0;
}

void taoMangCauHoi(NodeCauHoi *rootCauHoi, mangCauHoi &dsCauHoi, string maMon)
{

    // duyet LNR
    if (rootCauHoi != nullptr)
    {
        if (rootCauHoi->info.maMonHoc == maMon)
        {
            dsCauHoi.arrCauHoiThi[dsCauHoi.tongSoCau] = rootCauHoi;
            dsCauHoi.tongSoCau++;
        }
        taoMangCauHoi(rootCauHoi->left, dsCauHoi, maMon);
        taoMangCauHoi(rootCauHoi->right, dsCauHoi, maMon);
    }
}

int TreeToArray(NodeCauHoi *rootCauHoi, NodeCauHoi *arrCauHoi[], int i)
{
    if (rootCauHoi == nullptr)
    {
        return i;
    }

    arrCauHoi[i] = rootCauHoi;
    i++;
    if (rootCauHoi->left != nullptr)
    {
        i = TreeToArray(rootCauHoi->left, arrCauHoi, i);
    }

    if (rootCauHoi->right != nullptr)
    {
        i = TreeToArray(rootCauHoi->right, arrCauHoi, i);
    }

    return i;
}