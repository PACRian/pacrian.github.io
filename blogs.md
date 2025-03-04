---
layout: default
title: Blogs - Pacria's Site
---

<style>
  .navigation {
    text-align: center;
    padding: 20px 0;
    font-family: Arial, sans-serif;
  }
  .navigation a {
    margin: 0 30px;
    text-decoration: none;
    color: #333;
    font-size: 18px;
  }
  .content {
    max-width: 800px;
    margin: 0 auto;
    padding: 20px;
    font-family: Arial, sans-serif;
  }
  .category {
    margin-bottom: 20px;
  }
  .category-header {
    cursor: pointer;
    font-size: 18px;
    font-weight: bold;
    margin-bottom: 10px;
  }
  .category-header::before {
    content: "> ";
  }
  .category-content {
    margin-left: 20px;
    display: none;
  }
  .category.active .category-content {
    display: block;
  }
  .article-item {
    margin-bottom: 10px;
    list-style-type: none;
  }
  .article-item::before {
    content: "· ";
  }
  .article-date {
    color: #666;
    font-size: 14px;
    margin-right: 10px;
  }
  .article-tags {
    display: inline-block;
    color: #888;
    font-size: 12px;
    margin-left: 10px;
  }
</style>

<div class="navigation">
  <a href="index.html">Home</a>
  <a href="blogs.html">Blogs</a>
  <a href="about.html">About</a>
</div>

<div class="content">
  {% assign categories = site.tutorials | map: "categories" | flatten | uniq %}
  {% for category in categories %}
  <div class="category">
    <div class="category-header" onclick="toggleCategory(this)">{{ category }}</div>
    <div class="category-content">
      <ul style="padding-left: 0;">
        {% assign category_posts = site.tutorials | where_exp: "item", "item.categories contains category" %}
        {% for post in category_posts %}
        <li class="article-item">
          <span class="article-date">{{ post.date | date: "%Y-%m-%d" }}</span>
          <a href="{{ post.url | relative_url }}">{{ post.title }}</a>
          <span class="article-tags">
            {% for tag in post.tags %}
            <span class="tag">{{ tag }}</span>
            {% endfor %}
          </span>
        </li>
        {% endfor %}
      </ul>
    </div>
  </div>
  {% endfor %}
</div>

<script>
  function toggleCategory(element) {
    const parentCategory = element.parentElement;
    parentCategory.classList.toggle('active');
  }
  
  // Open the first category by default
  document.addEventListener('DOMContentLoaded', function() {
    const firstCategory = document.querySelector('.category');
    if (firstCategory) {
      firstCategory.classList.add('active');
    }
  });
</script>