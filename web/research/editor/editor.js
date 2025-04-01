import { EditorState } from '@codemirror/state';
import { EditorView, lineNumbers, keymap } from '@codemirror/view';
import { defaultKeymap, historyKeymap, insertTab, history } from '@codemirror/commands';
import { StreamLanguage, indentOnInput } from '@codemirror/language';
import { closeBrackets, closeBracketsKeymap } from '@codemirror/autocomplete';
import { stex } from '@codemirror/legacy-modes/mode/stex';
import { dracula } from '@uiw/codemirror-theme-dracula';

function createEditorState(initialContent) {
    let extensions = [
        dracula,
        EditorView.lineWrapping,
        lineNumbers(),
        indentOnInput(),
        history(),
        closeBrackets(),
        StreamLanguage.define(stex),
        keymap.of([
            { key: 'Tab', run: insertTab },
            ...defaultKeymap,
            ...historyKeymap,
            ...closeBracketsKeymap
        ])
    ];

    return EditorState.create({
        doc: initialContent,
        extensions
    });
}

function createEditorView(state, parent) {
    return new EditorView({ state, parent });
}

export { createEditorState, createEditorView };
