function getModeCodeMirror(t){let e=[{name:"C",mime:"text/x-csrc",mode:"clike",ext:["c","h","ino"]},{name:"Cpp",mime:"text/x-c++src",mode:"clike",ext:["cpp","c++","cc","cxx","hpp","h++","hh","hxx"],alias:["cpp"]},{name:"Cpp14",mime:"text/x-c++src",mode:"clike",ext:["cpp","c++","cc","cxx","hpp","h++","hh","hxx"],alias:["cpp"]},{name:"csharp",mime:"text/x-csharp",mode:"clike",ext:["cs"],alias:["csharp"]},{name:"CSS",mime:"text/css",mode:"css",ext:["css"]},{name:"HTML",mime:"text/html",mode:"htmlmixed",ext:["html","htm","handlebars","hbs"],alias:["xhtml"]},{name:"xml",mime:"text/html",mode:"htmlmixed",ext:["html","htm","handlebars","hbs"],alias:["xhtml"]},{name:"Java",mime:"text/x-java",mode:"clike",ext:["java"]},{name:"JavaScript",mime:"text/javascript",mode:"javascript",ext:["js"],alias:["ecmascript","js","node"]},{name:"jscript",mime:"text/javascript",mode:"javascript",ext:["js"],alias:["ecmascript","js","node"]},{name:"JSON",mimes:["application/json","application/x-json"],mode:"javascript",ext:["json","map"],alias:["json5"]},{name:"MySQL",mime:"text/x-mysql",mode:"sql"},{name:"Objc",mime:"text/x-objectivec",mode:"clike",ext:["m","mm"],alias:["objective-c","objc"]},{name:"Perl",mime:"text/x-perl",mode:"perl",ext:["pl","pm"]},{name:"PHP",mime:"text/x-php",mode:"php",ext:["php","php3","php4","php5","php7","phtml"]},{name:"Python",mime:"text/x-python",mode:"python",ext:["BUILD","bzl","py","pyw"],file:/^(BUCK|BUILD)$/},{name:"Python3",mime:"text/x-python",mode:"python",ext:["BUILD","bzl","py","pyw"],file:/^(BUCK|BUILD)$/},{name:"R",mime:"text/x-rsrc",mode:"r",ext:["r","R"],alias:["rscript"]},{name:"Ruby",mime:"text/x-ruby",mode:"ruby",ext:["rb"],alias:["jruby","macruby","rake","rb","rbx"]},{name:"Scala",mime:"text/x-scala",mode:"clike",ext:["scala"]},{name:"SQL",mime:"text/x-sql",mode:"sql",ext:["sql"]},{name:"SQLite",mime:"text/x-sqlite",mode:"sql"},{name:"Swift",mime:"text/x-swift",mode:"swift",ext:["swift"]},{name:"LaTeX",mime:"text/x-latex",mode:"stex",ext:["text","ltx","tex"],alias:["tex"]},{name:"VB.NET",mime:"text/x-vb",mode:"vb",ext:["vb"]},{name:"Vue.js Component",mime:"text/x-vue",mode:"vue",ext:["vue"]}],o=t;"node"!==t&&"nodejs"!==t||(o="javascript");for(var i=0;i<e.length;i++){var n=e[i];if(n.name.toLowerCase()==o)return n;if(n.alias)for(var s=0;s<n.alias.length;s++)if(n.alias[s].toLowerCase()==name)return n}}(()=>{var t=document.currentScript?document.currentScript.getAttribute("environment"):null;let e=document.currentScript?document.currentScript.getAttribute("domain"):null,i=document.currentScript?document.currentScript.getAttribute("no-scroll"):null,r="https://codejudge.geeksforgeeks.org/",a="https://assets.geeksforgeeks.org/codetabs",n=["c","cpp","cpp14","csharp","java","javascript","html","css","node","perl","php","python","python3","py","py3","scala"],o=("development"===t?(r="https://codejudgetest.geeksforgeeks.org/",a="https://assets.geeksforgeeks.org/codetabs-dev"):"local"===t&&(r="https://codejudgetest.geeksforgeeks.org/",a="/static-tabs"),document.createElement("template")),d=!1,l,s=`<svg xmlns="http://www.w3.org/2000/svg" class="gfg-icon" width="20" height="20" viewBox="0 0 24 24" stroke-width="2.0" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
        <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
        <path d="M12 3c.132 0 .263 0 .393 0a7.5 7.5 0 0 0 7.92 12.446a9 9 0 1 1 -8.313 -12.454z" />
    </svg> `,c=`
        <div class="border" id="edit-code-loader" class="gfg-icon" hidden></div>
        <svg xmlns="http://www.w3.org/2000/svg" id="edit-close-icon" class="gfg-icon" width="20" height="20" viewBox="0 0 24 24" stroke-width="2.0" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
            <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
            <path d="M4 20h4l10.5 -10.5a1.5 1.5 0 0 0 -4 -4l-10.5 10.5v4" />
            <path d="M13.5 6.5l4 4" />
        </svg>`;o.innerHTML=`
    <style>
      :host {
        display: flex;
        flex-wrap: wrap;
      }
      ::slotted(gfg-panel) {
        flex-basis: 100%;
      }
      .codeblock-container[data-content]::after,
      .codeblock-container[data-danger-content]::after {
        content: attr(data-content);
        display: block;
        position: absolute;
        bottom: 0;
        right: 0;
        padding: 4px 12px;
        font-size: 12px;
        letter-spacing: 0.05em;
        font-family: inherit;
        background-color: rgb(217, 217, 217);
        color: #424242 !important;
      }
      .codeblock-container[data-danger-content]::after {
        color: rgb(132, 5, 5) !important;
        content: attr(data-danger-content);
      }
      .codeblock-container{
        position: relative;
        width: 100%;
        font-family: sans-serif;
      }
      .code-container{
        display: flex;
        flex-direction: column;
        border: 1px solid #ddd;
        clear: left;

      }
      
      #slot-panel::-webkit-scrollbar-track {
        border-radius: 10px;
        background-color: #e0e0e0;
        width: 8px !important;
      }

      #slot-panel::-webkit-scrollbar-thumb {
        border-radius: 10px;
        background-color: #999;
        width: 8px ; 
      }
      #slot-panel::-webkit-scrollbar {
        width: 8px; 
      }
      #slot-panel::-webkit-scrollbar-thumb:hover {
        cursor: pointer;
      }
      .editor-buttons-div,
      .w-56 {
        min-width: 56px;
      }
        .editor-buttons-div{
            display: flex;
            flex-direction: column;
            justify-content: flex-start;
        }
      .gfg-code{
        padding: 0;
        width: 100%;
      }
      .editor-buttons{
        display:flex;
        flex-direction: column;
        position: sticky;
        position: -webkit-sticky;
        top: 100px;
        margin-top: 20px;
        align-items: center;
      }
      .editor-buttons.output-box {
        margin-top: 0px;
      }
      .editor-buttons.output-box button {
        margin-bottom: 0 !important;
      }
      .code-button{
        background: white;
        margin-bottom: 10px;
        border: 2px;
        background: #e5e5e5;
        border-radius: 50px;
        width: 34px !important;
        height: 34px !important;
        cursor: pointer;
      }
        #expand-code-button{
            margin-bottom: 0px;
        }
      .code-output{
        background: #efefef;
        border-radius: 8px;
        width: 100%;
        margin: 10px 2px 5px 2px;
      }
      .close-output-button{
        margin-bottom: 10px;
      }
      .code-output-content{
        padding: 8px 16px;
        margin: 0;
        position: sticky;
        position: -webkit-sticky;
        margin-top: 10px;
      }
      .code-box {
        display: flex;
      }
      .code-output-box {
        display: flex;
        align-items: center;
      }
      .generated-output{
        font-size: 15px;
        white-space: pre-wrap;
      }
      .row-output{
        color: black;
        font-size: 16px;
        padding : 10px;
      }
      .border {
        width: 34px !important;
        height: 34px !important;
        position: absolute;
        background: transparent;
        border-radius: 50%;
        border: 2px dashed #000;
        margin-left: -8px;
        margin-top: -9px;
        animation-name: rotate;
        animation-duration: 5s;
        animation-iteration-count: infinite;
        animation-timing-function: linear;
      }
      .codeblock-container[data-mode=dark] .border {
        border-color: white !important;
      }
      #icon-tabler-copy{
        margin-bottom: -4px;
        cursor: pointer;
      }
      .gfg-icon{
        margin-left: auto;
        margin-right: auto;
        display: block !important;
      }
      
        @keyframes rotate {
            from{ transform: rotate(-360deg); }
            to{ transform: rotate(360deg); }
        }
        #code-output-element #jsFrame {
            background-color: transparent;
            border: unset;
            width: 100%;
        }
    </style>

    <div class="codeblock-container">
        <slot name="tab"></slot>
        <div class="code-container">
            <div class="code-box">
                <div id="editor-buttons-div" class="editor-buttons-div" >
                    <div id="editor-buttons" class="editor-buttons">
                        <button class="code-button" id="copy-code-button" title="Copy Code">
                            <svg xmlns="http://www.w3.org/2000/svg"  class="gfg-icon" width="20" height="20" viewBox="0 0 24 24" stroke-width="2.0" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
                            <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
                            <path d="M8 8m0 2a2 2 0 0 1 2 -2h8a2 2 0 0 1 2 2v8a2 2 0 0 1 -2 2h-8a2 2 0 0 1 -2 -2z" />
                            <path d="M16 8v-2a2 2 0 0 0 -2 -2h-8a2 2 0 0 0 -2 2v8a2 2 0 0 0 2 2h2" />
                            </svg>
                        </button>
                        <button class="code-button" id="edit-close-button" title="Edit Code">
                            ${c}
                        </button>
                        <button class="code-button" id="run-code-button" title="Run Code and See Output">
                            <div class="border" id="run-code-loader" class="gfg-icon" hidden></div>
                            <svg xmlns="http://www.w3.org/2000/svg" class="gfg-icon" width="20" height="20" viewBox="0 0 24 24" stroke-width="2.0" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
                                <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
                                <path d="M7 4v16l13 -8z" />
                            </svg>
                        </button>
                        <button class="code-button" id="mode-button"  title="Light mode">
                            ${s}
                        </button>
                    </div>
                </div>
                <div id="slot-panel" class="gfg-code">
                    <slot name="panel"></slot>
                </div>
            </div>
            <div class="code-output-box" id="code-output-box" >
                <div class="editor-buttons w-56 output-box" title="Close Output">
                    <button class="code-button" id="close-output-button" hidden>
                        <svg xmlns="http://www.w3.org/2000/svg" class="gfg-icon" width="20" height="20" viewBox="0 0 24 24" stroke-width="1.5" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
                            <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
                            <path d="M9 12h-3.586a1 1 0 0 1 -.707 -1.707l6.586 -6.586a1 1 0 0 1 1.414 0l6.586 6.586a1 1 0 0 1 -.707 1.707h-3.586v6h-6v-6z" />
                            <path d="M9 21h6" />
                        </svg>
                    </button>
                </div> 
                <div class="code-output" id="code-output" hidden>
                    <div class="row-output">
                        <pre class="generated-output" id="code-output-element"></pre>
                    </div> 
                </div>
            </div>
            </div>
        </div>
    </div>
    `;class h extends HTMLElement{constructor(){super(),this._defaultLanguage=this._getDefaultLanguage(),this._onSlotChange=this._onSlotChange.bind(this),this._copyCode=this._copyCode.bind(this),this._runCode=this._runCode.bind(this),this._editClose=this._editClose.bind(this),this._closeOutput=this._closeOutput.bind(this),this._closeButton=this._closeButton.bind(this),this._changeMode=this._changeMode.bind(this),this._setInitialtheme=this._setInitialtheme.bind(this),this._runStaticCode=this._runStaticCode.bind(this),this._getCode=this._getCode.bind(this),this._setupCollapsibleCodeButtons=this._setupCollapsibleCodeButtons.bind(this),this.currentSelectedTab=!1,this.attachShadow({mode:"open"}),this.shadowRoot.appendChild(o.content.cloneNode(!0)),this._tabSlot=this.shadowRoot.querySelector("slot[name=tab]"),this._panelSlot=this.shadowRoot.querySelector("slot[name=panel]"),this._codeElement=this.shadowRoot.querySelector("div[id=slot-panel]"),this._copyCodeElement=this.shadowRoot.querySelector("button[id=copy-code-button]"),this._runCodeElement=this.shadowRoot.querySelector("button[id=run-code-button]"),this._editCloseElement=this.shadowRoot.querySelector("button[id=edit-close-button]"),this._closeOutputButton=this.shadowRoot.querySelector("button[id=close-output-button]"),this._ModeButton=this.shadowRoot.querySelector("button[id=mode-button]"),this._codeOutputBox=this.shadowRoot.querySelector("div[id=code-output]"),this._editorButtonDiv=this.shadowRoot.querySelector("div[id=editor-buttons-div]"),this._editorButtons=this.shadowRoot.querySelector("div[id=editor-buttons]"),this._backGround=document.querySelector("#data-mode"),this._backGround||(this._backGround=document.getElementsByTagName("body")[0]),this._setInitialtheme();let e=()=>{this._setInitialtheme()};new MutationObserver(function(t){t.forEach(t=>{if("attributes"===t.type)switch(t.attributeName){case"data-dark-mode":case"data-theme":e()}})}).observe(this._backGround,{attributeFilter:["data-dark-mode","data-theme"],subtree:!0}),this._tabSlot.addEventListener("slotchange",this._onSlotChange),this._panelSlot.addEventListener("slotchange",this._onSlotChange),this._copyCodeElement.addEventListener("click",this._copyCode),this._runCodeElement.addEventListener("click",this._runCode),this._editCloseElement.addEventListener("click",this._editClose),this._closeOutputButton.addEventListener("click",this._closeOutput),this._ModeButton.addEventListener("click",this._changeMode)}connectedCallback(){this.addEventListener("click",this._onClick),this.hasAttribute("role")||this.setAttribute("role","tablist"),this._getCode(!1).split("\n").length<7&&this._setupCollapsibleCodeButtons(),this.getAttribute("code-editor")&&this._editorButtonDiv&&(this._editorButtonDiv.style.display="none");let t=this;for(;null!=t;){if(t.className.includes("hide-codetabs-buttons")){var e=this._editorButtonDiv;e&&e.remove();break}t=t.parentElement}Promise.all([customElements.whenDefined("gfg-tab"),customElements.whenDefined("gfg-panel")]).then(t=>this._linkPanels())}disconnectedCallback(){this.removeEventListener("keydown",this._onKeyDown),this.removeEventListener("click",this._onClick),this.removeEventListener("click",this._copyCode),this.removeEventListener("click",this._runCode),this.removeEventListener("click",this._editClose),this.removeEventListener("click",this._closeButton),this.removeEventListener("click",this._closeOutput),this.removeEventListener("click",this._changeMode)}_onSlotChange(t){this._linkPanels()}_linkPanels(){var t=this._allTabs(),t=(t.forEach(t=>{var e=t.nextElementSibling;e&&e.tagName&&"gfg-panel"!==e.tagName.toLowerCase()?console.error(`Tab #${t.id} is not a`+"sibling of a <gfg-panel>"):e&&t&&(t.setAttribute("aria-controls",e.id),e.setAttribute("aria-labelledby",t.id),e.getAttribute("data-code-lang")==this._defaultLanguage)&&t.setAttribute("selected",!0)}),t.find(t=>t.selected)||t[0]);this._selectTab(t)}_allPanels(){return Array.from(this.querySelectorAll("gfg-panel"))}_getSelectedPanel(){return this._allPanels().find(t=>!1===t.hidden)}_allTabs(){return Array.from(this.querySelectorAll("gfg-tab"))}_panelForTab(t){t=t.getAttribute("aria-controls");if(""!==t)return this.querySelector("#"+t)}reset(){var t=this._allTabs(),e=this._allPanels();t.forEach(t=>t.selected=!1),e.forEach(t=>t.hidden=!0)}_selectTab(t){if(this.reset(),t){var e=t.nextElementSibling;if(!e)throw new Error("No panel with id");e.hidden=!(t.selected=!0);var t=this.getAttribute("data-run-ide"),o=this._getSelectedPanel().getAttribute("data-code-lang");return"true"===t&&n.includes(o)?this._runCodeElement.hidden=this._editCloseElement.hidden=!1:this._runCodeElement.hidden=this._editCloseElement.hidden=!0,e}}_onClick(t){if("tab"===t.target.getAttribute("role")){this._setTabMessage("",!1,!0),this._closeButton(t);var e,o=this._selectTab(t.target);this._closeOutput(t),l&&l.abort();try{o&&(e=o.getAttribute("data-code-lang"),this._setDefaultLanguageCookie(e))}catch{}}}_copyCode(t){let e="";try{e=d?d.getValue():this._getSelectedPanel().querySelector("pre").innerText,navigator.clipboard.writeText(e),this._setTabMessage("Code Copied!")}catch(t){this._setTabMessage("Error copying code",!0),console.log(t)}}_openLoginModal(){var t=document.querySelector(".header-main__container .login-modal-btn");return!t||"gfg"!==e||(t.click(),!1)}_runStaticCode(e){try{let t=this._codeOutputBox.querySelector("#code-output-element");require.config({packages:[{name:"StaticCodeCompiler",location:""+a,main:a+"/StaticCodeCompilerV1.min.js"}],waitSeconds:20}),require([a+"/StaticCodeCompilerV1.min.js"],function(){window.StaticCodeCompiler(e,!0,t)})}catch(t){console.log(t),codeOutputElement.innerHTML="Some Error Occured"}}async _runCode(){var i=this._openLoginModal();if(i&&(this._setTabMessage("",!1,!0),l=new AbortController,!this.loader||this.loader.hidden)){try{this._codeOutputBox.hidden=!1,this._closeOutputButton.hidden=!1,this._codeOutputBox.scrollIntoView({behavior:"smooth",block:"center"})}catch(t){return void console.log(t)}var n=this._codeOutputBox.querySelector("#code-output-element"),s="Some Error Occured, Please Try Again";this.loader=this._runCodeElement.querySelector("#run-code-loader"),this.loader.hidden=!1,this._runCodeElement.disabled=!0,n.innerHTML="Compiling...";let o=this._getSelectedPanel().getAttribute("data-code-lang");i=d?d.getValue():this._getSelectedPanel().querySelector("pre").innerText;if(["html","css"].includes(o))this._runStaticCode(i);else{let t,e;["javascript","jscript","node"].includes(o)&&(o="js");try{if("ERROR"===(t=await(t=await fetch(r+"submit-request",{signal:l.signal,method:"POST",withCredentials:!1,headers:{Accept:"application/json","Content-Type":"application/json"},body:JSON.stringify({language:o,code:i,input:"",save:!1})})).json()).status||!t.submission_id)return n.innerHTML=s,this.loader.hidden=!0,void(this._runCodeElement.disabled=!1)}catch(t){return n.innerHTML=s,this.loader.hidden=!0,void(this._runCodeElement.disabled=!1)}for(;;){try{e=await(e=await fetch(r+"get-status/"+t.submission_id,{signal:l.signal,method:"GET",withCredentials:!1,headers:{Accept:"application/json","Content-Type":"application/json"}})).json()}catch(t){return console.log(t),this.loader.hidden=!0,this._runCodeElement.disabled=!1,void(n.innerHTML=s)}if(!["IN-QUEUE","in-queue"].includes(e.status))break;await new Promise(t=>setTimeout(t,3e3))}if(e){let t;t=e.output||e.rntError||e.cmpError,n.innerHTML=t||"No Output"}else n.innerHTML=s}this.loader.hidden=!0,this._runCodeElement.disabled=!1}}async _editClose(t){if(this._openLoginModal())if(this._setTabMessage("",!1,!0),"edit"===this._editCloseElement.getAttribute("buttonType"))this._closeButton(t);else{console.log("Her.e.e.e...");let n=this._editCloseElement;t=n.querySelector("#edit-code-loader");t&&(t.hidden=!1);try{let e=this._getSelectedPanel(),o=e.querySelector("pre").innerText,i="dark"===this._ModeButton.getAttribute("mode")?"monokai":"default";var s=e.getAttribute("data-code-lang").toLowerCase(),r=(require.config({packages:[{name:"codemirror",location:a+"/codemirror",main:"lib/codemirror"}],waitSeconds:20}),getModeCodeMirror(s));console.log("Here.....",r),require(["codemirror",`codemirror/mode/${r.mode}/`+r.mode,"codemirror/addon/mode/loadmode","codemirror/addon/selection/active-line"],function(t){n.setAttribute("buttonType","edit"),n.setAttribute("title","Close Editor"),e.querySelector("pre").hidden=!0,n.innerHTML=`<svg xmlns="http://www.w3.org/2000/svg"  id="edit-close-icon" class="gfg-icon" width="20" height="20" viewBox="0 0 24 24" stroke-width="2.0" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
        <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
        <path d="M18 6l-12 12" />
        <path d="M6 6l12 12" />
    </svg>`,(d=t(e,{extraKeys:{"Ctrl-Space":"autocomplete"},mode:r.mime,value:o,theme:i,autofocus:!0,lineNumbers:!0,styleActiveLine:!0})).focus(),d.refresh()})}catch(t){console.log(t)}}}_closeButton(t){this._editCloseElement.setAttribute("buttonType","close"),this._editCloseElement.setAttribute("title","Edit Code"),this._editCloseElement.innerHTML=c;var e=this._getSelectedPanel(),e=(e.querySelector("pre").hidden=!1,d=!1,e.querySelector(".CodeMirror"));e&&e.parentNode.removeChild(e)}_closeOutput(t){this._codeOutputBox.hidden=!0,this._closeOutputButton.hidden=!0,this._codeOutputBox.querySelector("#code-output-element").innerHTML="Compiling...."}_setInitialtheme(t){if(this._backGround){var e=this.shadowRoot.querySelector(".codeblock-container");let t=this._backGround.getAttribute("data-theme");t=t||this._backGround.getAttribute("data-dark-mode");var o=["dark","true"].indexOf(t)<0?"dark":"light";this._ModeButton.setAttribute("mode",o),!this.hasAttributes()&&window.location.hostname.includes("write")||(this.setAttribute("data-mode","dark"==o?"light":"dark"),e.setAttribute("data-mode","dark"==o?"light":"dark")),this._changeMode()}null===i||"false"===i?(e=this.shadowRoot.querySelector("div[id=slot-panel]"))&&(e.style.maxHeight="70vh",e.style.overflowY="auto"):(o=this.shadowRoot.querySelector(".gfg-code"))&&(o.style.width="calc(100% - 64px)")}_changeMode(t){this._setTabMessage("",!1,!0);var e=this._ModeButton.getAttribute("mode");let o={mode:"dark",title:"Light Mode",icon:`<svg xmlns="http://www.w3.org/2000/svg" class="gfg-icon" width="20" height="20" viewBox="0 0 24 24" stroke-width="1.5" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
        <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
        <path d="M14.828 14.828a4 4 0 1 0 -5.656 -5.656a4 4 0 0 0 5.656 5.656z" />
        <path d="M6.343 17.657l-1.414 1.414" /><path d="M6.343 6.343l-1.414 -1.414" /><path d="M17.657 6.343l1.414 -1.414" /><path d="M17.657 17.657l1.414 1.414" /><path d="M4 12h-2" /><path d="M12 4v-2" /><path d="M20 12h2" /><path d="M12 20v2" />
    </svg>`,theme:"monokai"};-1<["dark"].indexOf(e)&&(o={mode:"light",title:"Dark Mode",icon:s,theme:"default"}),this._ModeButton.setAttribute("mode",o.mode),this._ModeButton.setAttribute("title",o.title),this._ModeButton.innerHTML=o.icon,this._allPanels().forEach(t=>{t.querySelector("div.highlight")&&("dark"===o.mode?t.querySelector("div.highlight").classList.add("monokai"):t.querySelector("div.highlight").classList.remove("monokai"))}),d&&((e=document.getElementsByClassName("CodeMirror"))&&e[0]&&("default"===o.theme?e[0].style.backgroundColor="white":e[0].style.backgroundColor=""),d.setOption("theme",o.theme))}_getDefaultLanguage(){let e="";var o=document.cookie.split(";");for(let t=0;t<o.length;t++){var i=o[t].split("=");"default_lang"==i[0].trim()&&(e=i[1].trim())}return e}_setDefaultLanguageCookie(t){var e;t!=this._defaultLanguage&&(e=parseInt((new Date).getFullYear())+2,document.cookie=`default_lang=${t}; expires=Sat, 01 Jan ${e} 00:00:01 GMT; domain=.geeksforgeeks.org; path=/`)}async _setTabMessage(t,e=!1,o=!1){var i=this.shadowRoot.querySelector(".codeblock-container");o?(i.removeAttribute("data-danger-content"),i.removeAttribute("data-content")):(i.setAttribute(e?"data-danger-content":"data-content",t||"Some error occurred"),await new Promise(t=>setTimeout(t,3e3)),this._setTabMessage("",!1,!0))}_getCode(t=!0){let e="";return e=t&&d?d.getValue():this._getSelectedPanel().querySelector("pre").innerText}_setupCollapsibleCodeButtons(){if(this._editorButtonDiv){Array.from(this._editorButtons.children).forEach(t=>t.style.display="none"),this._editorButtonDiv.style.justifyContent="center",this._editorButtons.style.marginTop="0px";let t=document.createElement("button"),e=(t.innerHTML=`<svg xmlns="http://www.w3.org/2000/svg" class="gfg-icon" width="20" height="20" viewBox="0 0 24 24" stroke-width="2" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
        <line x1="3" y1="6" x2="21" y2="6"></line>
        <line x1="3" y1="12" x2="21" y2="12"></line>
        <line x1="3" y1="18" x2="21" y2="18"></line>
    </svg>`,t.className="code-button",t.id="expand-code-button",t.title="Expand",document.createElement("button"));e.innerHTML=`<svg xmlns="http://www.w3.org/2000/svg" class="gfg-icon" width="20" height="20" viewBox="0 0 24 24" stroke-width="2" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
        <polyline points="18 15 12 9 6 15"></polyline>
        <polyline points="18 9 12 3 6 9"></polyline>
    </svg>`,e.className="code-button",e.id="collapse-code-button",e.title="Collapse",e.style.display="none",e.addEventListener("click",()=>{Array.from(this._editorButtons.children).forEach(t=>t.style.display="none"),this._editorButtonDiv.style.justifyContent="center",t.style.display="",e.style.display="none",this._editorButtons.style.marginTop="0px"}),t.addEventListener("click",()=>{Array.from(this._editorButtons.children).forEach(t=>t.style.display=""),e.style.display="",t.style.display="none",this._editorButtonDiv.style.justifyContent="flex-start",this._editorButtons.style.marginTop="20px"}),this._editorButtons.append(t),this._editorButtons.append(e)}}}customElements.define("gfg-tabs",h);let u=0;class p extends HTMLElement{static get observedAttributes(){return["selected"]}connectedCallback(){this.setAttribute("role","tab"),this.id||(this.id="gfg-tab-generated-"+u++),this.setAttribute("aria-selected","false"),this.setAttribute("tabindex",-1),this._upgradeProperty("selected")}_upgradeProperty(t){var e;this.hasOwnProperty(t)&&(e=this[t],delete this[t],this[t]=e)}attributeChangedCallback(){var t=this.hasAttribute("selected");this.setAttribute("aria-selected",t),this.setAttribute("tabindex",t?0:-1)}set selected(t){(t=Boolean(t))?this.setAttribute("selected",""):this.removeAttribute("selected")}get selected(){return this.hasAttribute("selected")}}customElements.define("gfg-tab",p);let m=0;class g extends HTMLElement{connectedCallback(){this.setAttribute("role","tabpanel"),this.id||(this.id="gfg-panel-generated-"+m++)}}customElements.define("gfg-panel",g)})();