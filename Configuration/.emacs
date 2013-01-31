(display-time)

(global-font-lock-mode t)
(column-number-mode t)

(setq-default transient-mark-mode t)

(show-paren-mode t)
(setq-default make-backup-files nil)

(setq-default indent-tabs-mode nil)
(setq-default tab-width 4)
(setq indent-tabs-mode nil)
(setq tab-width 4)

(setq c-indent-level 4)
(setq c-continued-statement-offset 4)
(setq c-brace-offset -4)
(setq c-argdecl-indent 4)
(setq c-label-offset -4)
(setq c-basic-offset 4)
(global-set-key "\C-m" 'reindent-then-newline-and-indent)
(setq indent-tabs-mode nil)
(setq standard-indent 4)
(set-default-font "-outline-Consolas-normal-r-normal-normal-15-112-96-96-c-*-iso8859-1")

(load-theme 'tango-dark)

'(add-to-list 'load-path (expand-file-name "D:\.emacs.d"))

(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
  '(column-number-mode t)
  '(display-time-mode t)
  '(show-paren-mode t)
  '(transient-mark-mode t)
 )
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 )

(autoload 'csharp-mode "csharp-mode" "Major mode for editing C# code." t)
(setq auto-mode-alist
(append '(("\\.cs$" . csharp-mode)) auto-mode-alist))

(autoload 'powershell-mode "powershell-mode" "Major mode for editing PowerShell code." t)
(setq auto-mode-alist
(append '(("\\.ps1$" . powershell-mode)) auto-mode-alist))

(autoload 'python-mode "python-mode" "Major mode for editing Python code." t)
(setq auto-mode-alist
(append '(("\\.py$" . python-mode)) auto-mode-alist))
