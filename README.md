<p align="center">
  <a href="#">
    <img alt="JiYu Trainer" src="https://imengyu.top/assets/images/jy/JiYuTrainerLogo256.png" width="128">
  </a>
</p>
<p align="center">
  <img alt="JiYu Trainer Title" src="https://imengyu.top/assets/images/jy/JiYuTrainerTitle.png">
</p>
<p align="center">不再被極域電子教室控制</p>

<p align="center">
  <a href="#"><img src="https://img.shields.io/badge/language-C++-blue.svg"></a>
  <a href="https://github.com/imengyu/JiYuTrainer/releases"><img src="https://img.shields.io/badge/version-1.7-greeb.svg"></a>
  <a href="https://github.com/imengyu/JiYuTrainer/blob/master/LICENSE"><img src="https://img.shields.io/badge/liscence-MIT-orange.svg"></a>
</p>

---

> [!NOTE]
> **繁體中文化說明**：本儲存庫為 [imengyu/JiYuTrainer](https://github.com/imengyu/JiYuTrainer) 的繁體中文（台灣在地化用語）翻譯版本。原作者為「快樂的夢魚」（imengyu），原始碼與著作權均屬原作者所有，本版本僅進行介面、說明文件與資源之繁體化與編碼相容性修復。

簡介
---

本軟體研發目的就是為了對抗極域電子教室，如果您的學校電腦教室使用極域電子教室來控制學生電腦的話，本軟體很可能會幫到你。

> 講師講課無聊冗長緩慢？想自己動手操作練習，卻被全螢幕廣播控制，什麼都不能做？拔掉網路線後雖然自由了但又看不到老師的示範？

如果你被以上問題困擾，本軟體可能是您非常想要的。

這是一個可以使 **極域電子教室全螢幕廣播失效** 的軟體，也就是說，在被老師全螢幕廣播時，會將其自動調整為視窗模式，你不僅可以自由操作電腦，也還可以看老師的示範，自由與學習兩不誤；其還可以防止被老師控制，以及自動關閉「**黑屏安靜**」限制；由於本軟體是將全螢幕調整為視窗，因此老師並不會發現你斷線或是進行了非預期操作。

如果你喜歡這個軟體，不妨向你的好友推薦一下吧！

如果你覺得這個軟體不錯，不妨給個小星星⭐吧，你的喜歡是對作者最大的支持！

功能
---
* 在不影響極域正常運行的情況下將「全螢幕廣播」轉為「視窗廣播」模式，您不僅可自由操作電腦，也可看老師講解課程。
* 內建強制終止、啟動與停止極域 StudentMain.exe 處理程序功能，無需依賴其他工具。
* 內建破解極域解鎖與解除安裝密碼功能，支援新版極域。
* 反監視功能，經測試，開啟反監視後，教師端便無法監視您所使用的電腦。
* 防控制功能，防止教師透過極域遠端控制您所使用的電腦。
* 監控極域遠端執行命令，您可以自由選擇是否允許教師端遠端執行的命令。
* 透過極域電子教室向同儕的電腦遠端發送訊息或遠端執行指令。

下載
---

* [下載軟體最新版已編譯版本](https://raw.githubusercontent.com/imengyu/JiYuTrainer/master/Release/JiYuTrainer.exe) 

提示：**由於本軟體會對極域電子教室進行必要的操作（遠端注入、替換模組），部分防毒軟體可能會誤報，您可能需要暫時關閉防毒軟體或加入白名單**。

---

![截圖](https://imengyu.top/assets/images/jy/ScreenShots.png)

操作方法
---

本軟體專為新手設計，預設情況下，您不需要修改任何參數，直接執行 exe 並最小化即可，軟體會自動在背景運作。

> 附加說明：本軟體不依賴任何外部執行階段程式庫（Runtime），您只需複製一個 **JiYuTrainer.exe** 至目標電腦即可執行，本軟體已將所需的 DLL 內建打包，會自動進行釋放與載入。 

[完整說明文件](https://raw.githubusercontent.com/imengyu/JiYuTrainer/master/帮助.png)

---

常見提示與問答
---

**Q: 教師端限制了隨身碟（USB），要怎麼把 JiYuTrainer 複製到電腦上執行？** <br/>
**A: 您可以先卸載極域的過濾驅動程式再插入隨身碟。具體操作步驟如下：** <br/>

1. 先以系統管理員身分執行 cmd：
![CMD](https://imengyu.top/assets/images/jy/sc0.png)
2. 輸入以下指令卸載 TDFileFilter 驅動程式：
```
sc stop TDFileFilter 
sc delete TDFileFilter 
```
![sc](https://imengyu.top/assets/images/jy/sc1.png)

然後再插入隨身碟即可不受限制，能直接執行 JiYuTrainer。

**Q: 教師端限制了網路，要怎麼處理？** <br/>
**A: JiYuTrainer 可以自動卸載網路驅動程式，這通常有效。如果該方法無效，<br/>可嘗試下載 PCHunter 軟體，該軟體具備強力刪除驅動程式的方法（也可用來強制結束任何處理程序）**<br/>

1. 如圖開啟 PCHunter 軟體，切換至「驅動模組」頁面。
2. 找到極域的網路驅動程式「TDNetFilter.sys」，並選擇卸載驅動程式。
3. 稍候片刻並重新整理網頁，此時網路即可正常存取。
4. 建議也可順便將極域的其他相關處理程序一併結束，避免因驅動程式解除後引發系統藍底白字（藍屏）。

![pch](https://imengyu.top/assets/images/jy/pchunter1.png)

#### 已測試極域電子教室版本：

* 2010版 （5.01.64.942 / 5.01 Baseline）
* 2015豪華版
* 2016豪華版 （2.07.0.13488 / 2.07 CMPC） 

#### 作業系統版本支援: 

* 系統版本要求: Win7 / Win8 / Win8.1 / Win10

> 抱歉：因為近期版本做了較大改動，部分功能無法向下相容 Windows XP，因此後續版本的 JiYuTrainer 皆不再支援 Windows XP。
如果您需要在 Windows XP 上使用 JiYuTrainer，請使用[舊版](https://raw.githubusercontent.com/imengyu/JiYuTrainer/master/Release/JiYuTrainerOldForWinXP.exe)。

編譯與建置
---

| 支援的編譯工具：||
|:-|:-:|
| [Visual Studio](https://www.visualstudio.com/) 2019 | (推薦) |
| gcc 4.7+ (需自行設定環境) | (不推薦) |

|若需編譯驅動程式模組，還需要安裝:||
|:-|:-:|
|[WDK8](https://www.microsoft.com/en-us/download/details.aspx?id=42273) 或以上||

使用的第三方函式庫
---

*第三方函式庫已內建於專案中，無需自行安裝*

- [Jiyu_udp_attack](https://github.com/ht0Ruial/Jiyu_udp_attack) (由 ht0Ruial 大佬提供 UDP 攻擊原理程式碼)
- [curl](https://github.com/curl/curl) (用於自動更新模組)
- [mhook](https://github.com/martona/mhook) (用於 JiYu HOOKER 模組)
- [MemoryModule](https://github.com/fancycode/MemoryModule)
- [XZip-XUnZip](https://github.com/yuanjia1011/XZip-XUnZip)

其他說明
---

本專案的主要功能目標已大致完成，<br/>
作者也已畢業即將步入職場，未來不會再去電腦教室上課了😔，<br/>
後續可能沒有充裕時間進行功能迭代，因此除了重大 Bug 修復之外，基本上不會再進行大幅度更動。<br/>
<br/>
如果您有其他客製化需求，歡迎 Fork 本專案並自行研究擴充。<br/>
若您希望將自行開發的特殊功能整合至 JiYuTrainer 供大家使用，
可以在功能開發完成後發送 Pull Request，我會審核並合併至主分支中。<br/>
<br/>
如果您喜歡這個專案，<br/>
不妨推薦給您身邊的好友吧😉

授權條款
---

[MIT License](https://github.com/imengyu/JiYuTrainer/blob/master/LICENSE) (free, open source)
