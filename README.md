## 🚀 專案 Git 使用指南

這份指南包含了初次連結此專案的步驟，以及日常開發時最常用的 Git 指令。

### 1. 初次設定與連結專案
如果你是第一次參與這個專案，請根據你的情況選擇以下**其中一種**方式來連結：

#### 方法 A：複製遠端專案到本地 (最常見)
如果你已經在 GitHub/GitLab 上看到這個專案，請直接將它 Clone 到你的電腦中：
```bash
git clone <請替換成專案的_Git_網址>
cd <專案資料夾名稱>

git init
git add .
git commit -m "Initial commit"
git branch -M main
git remote add origin <請替換成專案的_Git_網址>
git push -u origin main
