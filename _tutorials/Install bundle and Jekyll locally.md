---
layout: post
title: "Install `Jekyll` locally for site development"
date: 2025-03-06
categories: ["Web Development"]
tags: ["Jekyll", "Installation"]
excerpt: "Today we will install `Bundler` and `Jekyll` locally for site development."
lang: en
translations:
  - lang: zh
    url: /tutorials/Install%20Bundler%20and%20Jekyll%20locally-zh/
  - lang: en
    url: /tutorials/Install%20Bundler%20and%20Jekyll%20locally/
---

## Environment Preparation

First, install the required Ruby environment. To do this, first install `rbenv` (Ruby version management tool).

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

After executing the above commands, you should see a list of available Ruby versions. Choose an appropriate version to install, such as:

```bash
rbenv install 3.1.6
```

Then use `rbenv global 3.1.6` to set the installed version as globally available. Finally, verify the Ruby installation:

```bash
$ ruby -v
ruby 3.1.6p260 (2024-05-29 revision a777087be6) [x86_64-linux]
```

Next, install Ruby's package management tool—[`gem`](https://rubygems.org/). Add the following configuration to `.bashrc` and execute:

```bash
echo '# Install Ruby Gems to ~/gems' >> ~/.bashrc
echo 'export GEM_HOME="$HOME/gems"' >> ~/.bashrc
echo 'export PATH="$HOME/gems/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

## Official Installation

Next, use `gem` to install `Bundler` and `Jekyll`:

```bash
# Install bundler
gem install bundler

# Install Jekyll
gem install jekyll

# Verify installation
bundle exec jekyll -v
```

You can check their installation versions with the following commands:

```bash
bundle -v
jekyll -v
```

## Local Testing

After entering the project directory, execute the following command to start the Jekyll service:

```bash
bundle exec jekyll serve
```

(or use the simplest command `jekyll serve`)

Here are some related advanced commands:

```bash
# Enable live reload (automatically refresh the browser after modifying files)
bundle exec jekyll serve --livereload

# Include draft content
bundle exec jekyll serve --draft

# Specify a different port
bundle exec jekyll serve --port 3000

# Accessible within the local network (e.g., for testing on a mobile device)
bundle exec jekyll serve --host 0.0.0.0

# Use incremental build (improve build speed for large sites)
bundle exec jekyll serve --incremental
```
