<center>
<img src="./AD/V0.3-alpha.3_AD.png" width="400">
</center>

# **正德人工智障**

<img src="./LOGO/zhengdeai.png" width="200">

這只是個垃圾項目,非真正要用AI的在下載

## 跳轉

- [跳轉](#跳轉) *(這個的意義是什麼?)*
- [更新日誌](#v03更新日誌)
- [特色功能](#特色功能)
- [關於模型](#關於模型)
- [可回應句子](#可回應句子)
- [編譯所需環境](#編譯所需環境)
- [Makefile](#makefile-僅限linux)

## ***V0.3*更新日誌**

- 增加一句可回應
- \n回老家了,\r來替代
- 加了個沒用的跳轉

## **特色功能**

- **十分有用**的加載
- 沒甚麼用的**安靜模式**
- 先進的**if else架構**
- 純手工句子**千篇一律**
- **CLI介面**
- 可暴力寫入**67**

## **關於模型**

- 參數量: **0B**
- 目前可回應句子: **13句**
- 回應語言: **繁體中文 + 英文**

## **可回應句子**

- 關於校長的頭
- 關於校長
- 中原在哪
- 關於你
- 生態池裡最多的是什麼
- 今年是西元幾年
- who are you
- 什麼是家政課
- boom *(謹慎使用)*
- 向陽廣場附近的聲音是什麼生物的
- 吃飯時適合配什麼
- 退出
- quit

## **編譯所需環境**

- Linux版編譯器:**`gcc`** / **`clang`** *(默認`gcc`)*
- windows版編譯器:**`mingw32-gcc`** *(默認`mingw32-gcc`)*
- 所需庫: **`stdio`**/**`stdlib`**/**`string`**/**`unistd`**/**`time`**
- 所需軟件: **ogg123** *(only Linux)*
- 但我已經打包好發行版了! *(僅windows X86-64和Linux X86-64,ogg123不包含在內)*

## **Makefile** *(僅限Linux)*

- **`make` / `make Linux`**: 編譯Linux優化後的版本
- **`make Linuxdebug`**: 編譯Linux未優化的版本
- **`make win`**: 編譯Windows優化後的版本
- **`make windebug`**: 編譯Windows未優化的版本
- **`make clean`**: 清理Linux版編譯後產物
- **`make cleanwin`**: 清理windows版編譯後產物
- **`make cleanall`**: 清理所有編譯後產物

---

就這樣,真的只是個拿來玩玩的垃圾