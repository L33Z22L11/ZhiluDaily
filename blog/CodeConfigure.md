# VSCode自用设置项

## 源文件

```json
{
  "editor.fontLigatures": true,
  "editor.cursorBlinking": "phase",
  "editor.cursorSmoothCaretAnimation": "on",
  "editor.mouseWheelZoom": true,
  "editor.renderWhitespace": "boundary",
  "editor.smoothScrolling": true,
  "editor.wordWrap": "on",
  "terminal.integrated.smoothScrolling": true,
  "workbench.list.smoothScrolling": true,
  "workbench.editor.wrapTabs": true,
  "C_Cpp.clang_format_fallbackStyle": "{BasedOnStyle: Chromium, IndentWidth: 4}",
}
```

## 各项目介绍

`"editor.fontLigatures": true`：启用字体连字特性。

`"editor.cursorBlinking": "phase"`：设置文本光标闪烁动画为渐变闪烁。

`"editor.cursorSmoothCaretAnimation": "on"`：设置文本光标平滑移动动画。

`"editor.mouseWheelZoom": true`：启用`Ctrl`+滚轮缩放编辑器字体大小。

`"editor.renderWhitespace": "boundary"`：将编辑器中的空格渲染为`·`，并隐藏字词之间的单个空格。

`"editor.smoothScrolling": true`：启用编辑器平滑滚动动画。

`"editor.wordWrap": "on"`：打开编辑器自动换行。

`"terminal.integrated.smoothScrolling": true`：启用终端平滑滚动动画。

`"workbench.list.smoothScrolling": true`：启用工作台平滑滚动动画。

`"workbench.editor.wrapTabs": true`：启用编辑器标签页自动换行，代替打开的标签页过多时标签页水平滚动的行为。

`"C_Cpp.clang_format_fallbackStyle": "{BasedOnStyle: Chromium, IndentWidth: 4}"`：设置VS Code的C/C++插件（`ms-vscode.cpptools`）的格式化方式与其他语言一致。