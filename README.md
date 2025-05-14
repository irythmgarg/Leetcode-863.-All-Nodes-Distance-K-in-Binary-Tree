# Leetcode-863.-All-Nodes-Distance-K-in-Binary-Tree

# 📡 Nodes at Distance K in Binary Tree

This project finds all nodes that are **exactly distance `k`** away from a given **target node** in a binary tree 🌲.  
It combines a **DFS** to map parent relationships with a **multi-directional recursive search** to collect the result 🌐.

---

## 🚀 What It Does

- 🔁 Builds a parent pointer map for each node  
- 📉 Recursively finds all nodes `k` steps below the target  
- 🔼 Also travels **upward** to parent nodes to explore other branches  
- ✅ Handles trees without cycles via a `visited` set

---

## 📊 Time and Space Complexity

| Operation                 | Time Complexity | Space Complexity |
|--------------------------|------------------|------------------|
| Preprocessing (DFS)      | O(n)             | O(n)             |
| Distance Traversal       | O(n)             | O(n)             |

- **n** = total number of nodes in the tree  
- The solution avoids cycles by keeping a `visited` set

---

## 🧑‍💻 Author

**👨‍🎓 Ridham Garg**  
🎓 *Thapar Institute of Engineering and Technology, Patiala*  
🏅 IBM Certified in AI and Data Science  
🏗️ Developer of real-time crack detection systems  
💊 Creator of surplus medicine sales platform  
🧠 Recursive and graph traversal enthusiast

---

## 🌟 Features

- 🎯 Supports arbitrary nodes as the target  
- 🌐 Traverses both up and down for full coverage  
- 🧼 Clean recursion with clear base cases  
- 🛡️ Uses a set to prevent revisiting nodes

---

> 📍 _"In a tree, distance is not just depth — it's direction."_  
