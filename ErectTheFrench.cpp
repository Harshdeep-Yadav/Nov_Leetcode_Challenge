class Solution {
public:
      int getRotationAngle(vector<int> A, vector<int> B, vector<int> C) {
        // (x2-x1)(y3-y1) - (y2-y1)(x3-x1) -> 3D Cross-product of AB and AC vectors
        return ((B[0] - A[0]) * (C[1] - A[1])) - ((B[1] - A[1]) * (C[0] - A[0]));
    }


    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {

        if (trees.size() <= 3) return trees;

        sort(trees.begin(), trees.end());


        vector<vector<int>> UpperHullTrees;

        UpperHullTrees.push_back(trees[0]);
        UpperHullTrees.push_back(trees[1]);
        for (int i = 2; i < trees.size(); i++) {
            int Us = UpperHullTrees.size();


            while (UpperHullTrees.size() >= 2 && getRotationAngle(UpperHullTrees[Us-2], UpperHullTrees[Us-1], trees[i]) > 0)
   {
                UpperHullTrees.pop_back();
                Us--;
            }
            UpperHullTrees.push_back(trees[i]);
        }

  
        vector<vector<int>> LowerHullTrees;

        LowerHullTrees.push_back(trees[trees.size() - 1]);
        LowerHullTrees.push_back(trees[trees.size() - 2]);

        for (int i = trees.size() - 3; i >= 0; --i) {

            int Ls = LowerHullTrees.size();

            while (LowerHullTrees.size() >= 2 && getRotationAngle(LowerHullTrees[Ls-2], LowerHullTrees[Ls-1], trees[i]) > 0) {
                LowerHullTrees.pop_back();
                Ls--;
            }
            LowerHullTrees.push_back(trees[i]);
        }


          UpperHullTrees.insert( UpperHullTrees.end(), LowerHullTrees.begin(), LowerHullTrees.end() );


        sort( UpperHullTrees.begin(), UpperHullTrees.end() );
        UpperHullTrees.erase( unique( UpperHullTrees.begin(), UpperHullTrees.end() ), UpperHullTrees.end() );

        return UpperHullTrees;
    }
};