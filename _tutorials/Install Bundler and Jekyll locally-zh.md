---
layout: post
title: "在本地部署 Jekyll"
date: 2025-03-06
categories: ["网络开发"]
tags: ["Jekyll", "Installation"]
excerpt: "Jekyll —— 一个简单的静态网站生成器"
lang: zh
translations:
    - lang: en
      url: /tutorials/Install%20bundle%20and%20Jekyll%20locally/
    - lang: zh
      url: /tutorials/Install%20Bundler%20and%20Jekyll%20locally-zh/
---


## 环境准备

首先，安装所需的Ruby环境，为此首先安装`rbenv`(Ruby的版本管理工具)

```bash
# Install dependencies
sudo apt-get update
sudo apt-get install -y build-essential libssl-dev zlib1g-dev

# Install rbenv
git clone https://github.com/rbenv/rbenv.git ~/.rbenv
echo 'export PATH="$HOME/.rbenv/bin:$PATH"' >> ~/.bashrc
echo 'eval "$(rbenv init -)"' >> ~/.bashrc
source ~/.bashrc

# Install ruby-build plugin
git clone https://github.com/rbenv/ruby-build.git ~/.rbenv/plugins/ruby-build

# List available Ruby versions
rbenv install -l
```

执行完上述内容后，应当看到可用的Ruby版本列表，选择适当的版本进行安装，如

```bash
rbenv install 3.1.6
```

然后使用`rbenv global 3.1.6`将刚才安装的版本设置为全局可用的，最后验证Ruby安装信息：

```bash
$ ruby -v
ruby 3.1.6p260 (2024-05-29 revision a777087be6) [x86_64-linux]
```

随后，安装Ruby的包管理工具—— [`gem`](https://rubygems.org/)，将下面的配置信息写入`.bashrc`，并执行

```bash
echo '# Install Ruby Gems to ~/gems' >> ~/.bashrc
echo 'export GEM_HOME="$HOME/gems"' >> ~/.bashrc
echo 'export PATH="$HOME/gems/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

## 正式安装
接下来，使用`gem`来安装`Bundler`和`Jekyll`
```bash

# Install bundler
gem install bundler

# Install Jekyll
gem install jekyll

# Verify installation
bundle exec jekyll -v
```
可以使用如下指令查看它们的安装版本：
```bash
bundle -v
jekyll -v
```

## 本地测试
进入项目目录后，执行下述指令以启动Jekyll服务：
```bash
bundle exec jekyll serve
```
(或使用最简单的指令`jekyll serve`)
下述是一些相关的高级指令：
```bash
# 启用实时重载（修改文件后自动刷新浏览器）
bundle exec jekyll serve --livereload

# 包含草稿内容
bundle exec jekyll serve --draft

# 指定不同端口
bundle exec jekyll serve --port 3000

# 在局域网内可访问（如用于在手机上测试）
bundle exec jekyll serve --host 0.0.0.0

# 使用增量构建（提高大型站点的构建速度）
bundle exec jekyll serve --incremental
```