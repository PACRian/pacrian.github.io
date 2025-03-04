---
layout: default
title: Blog - Pacria's Site
---

<style>
  /* Main content */
  .blog-container {
    max-width: 800px;
    margin: 0 auto;
    padding: 0 20px;
    font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Oxygen, Ubuntu, Cantarell, "Open Sans", "Helvetica Neue", sans-serif;
  }
  
  /* Blog header */
  .blog-header {
    margin: 60px 0 40px;
  }
  .blog-title {
    font-size: 48px;
    font-weight: 700;
    margin: 0;
    color: #111;
  }
  
  /* Post entries */
  .post-entry {
    margin-bottom: 60px;
  }
  .post-date {
    font-size: 16px;
    color: #555;
    margin-bottom: 10px;
  }
  .post-title {
    font-size: 28px;
    font-weight: 600;
    margin: 0 0 15px;
  }
  .post-title a {
    color: #111;
    text-decoration: none;
  }
  .post-title a:hover {
    text-decoration: underline;
  }
  .post-excerpt {
    font-size: 16px;
    line-height: 1.6;
    color: #444;
    margin: 0;
  }

  /* Responsive adjustments */
  @media (max-width: 768px) {
    .blog-title {
      font-size: 36px;
    }
    .post-title {
      font-size: 22px;
    }
  }
</style>

{% include navigation.html %}

<div class="blog-container">
  <header class="blog-header">
    <h1 class="blog-title">Blog</h1>
  </header>

  {% assign all_posts = site.tutorials | sort: 'date' | reverse %}
  {% for post in all_posts %}
  <div class="post-entry">
    <div class="post-date">{{ post.date | date: "%b %d, %Y" }}</div>
    <h2 class="post-title">
      <a href="{{ post.url | relative_url }}">{{ post.title }}</a>
    </h2>
    <p class="post-excerpt">{{ post.excerpt | strip_html | truncatewords: 25 }}</p>
  </div>
  {% endfor %}
</div>