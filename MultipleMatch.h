//
// Created by 46172 on 2020/12/31.
//

#ifndef UNTITLED3_MULTIPLEMATCH_H
#define UNTITLED3_MULTIPLEMATCH_H
#include "AdjMatrix.h"
#include <string.h>
class MultipleMatch {
public:
    void operator()(AdjMatrix&  g);
private:
    //static AdjMatrix& matrix;
    //static int mp[MAX][MAX];
    static bool used[MAX];
    static int cnt[MAX];
    static int cap[MAX];
    static int mat[MAX];
    bool dfs(int x);
    bool solve();

};


#endif //UNTITLED3_MULTIPLEMATCH_H
