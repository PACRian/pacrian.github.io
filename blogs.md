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
  
  /* Section divider */
  .section-divider {
    margin: 60px 0;
    border-top: 1px solid #eee;
  }
  
  /* Categories section */
  .categories-section {
    margin-bottom: 60px;
  }
  .categories-title {
    font-size: 32px;
    font-weight: 700;
    margin-bottom: 30px;
    color: #111;
  }
  
  /* Category panels */
  .category {
    margin-bottom: 20px;
    border: 1px solid #eee;
    border-radius: 4px;
  }
  .category-header {
    cursor: pointer;
    padding: 15px;
    font-size: 18px;
    font-weight: 600;
    background-color: #f8f8f8;
    border-radius: 4px;
    display: flex;
    justify-content: space-between;
    align-items: center;
  }
  .category-header::after {
    content: "↓";
    font-size: 14px;
    transition: transform 0.3s;
  }
  .category.active .category-header::after {
    transform: rotate(180deg);
  }
  .category-content {
    display: none;
    padding: 0 15px 15px;
  }
  .category.active .category-content {
    display: block;
  }
  
  /* Article list */
  .article-list {
    list-style-type: none;
    padding: 0;
    margin: 0;
  }
  .article-item {
    padding: 10px 0;
    border-bottom: 1px solid #f0f0f0;
  }
  .article-item:last-child {
    border-bottom: none;
  }
  .article-link {
    text-decoration: none;
    color: #333;
    display: flex;
    align-items: baseline;
  }
  .article-link:hover {
    color: #000;
  }
  .article-link:hover .article-title-text {
    text-decoration: underline;
  }
  .article-date {
    min-width: 100px;
    color: #888;
    font-size: 14px;
  }
  .article-title-text {
    flex-grow: 1;
  }
  .article-tags {
    display: flex;
    flex-wrap: wrap;
    gap: 5px;
    margin-top: 5px;
    margin-left: 100px;
  }
  .article-tag {
    background-color: #f0f0f0;
    padding: 2px 6px;
    border-radius: 3px;
    font-size: 12px;
    color: #666;
  }

  /* Responsive adjustments */
  @media (max-width: 768px) {
    .blog-title, .categories-title {
      font-size: 32px;
    }
    .post-title {
      font-size: 22px;
    }
    .article-link {
      flex-direction: column;
    }
    .article-date {
      margin-bottom: 5px;
    }
    .article-tags {
      margin-left: 0;
    }
  }
</style>

{% include navigation.html %}

<div class="blog-container">
  <!-- Chronological blog posts section -->
  <header class="blog-header">
    <h1 class="blog-title">Blog</h1>
  </header>

  {% assign all_posts = site.tutorials | sort: 'date' | reverse %}
  {% for post in all_posts limit:5 %}
  <div class="post-entry">
    <div class="post-date">{{ post.date | date: "%b %d, %Y" }}</div>
    <h2 class="post-title">
      <a href="{{ post.url | relative_url }}">{{ post.title }}</a>
    </h2>
    <p class="post-excerpt">{{ post.excerpt | strip_html | truncatewords: 25 }}</p>
  </div>
  {% endfor %}
  
  <!-- Divider between chronological and categories sections -->
  <div class="section-divider"></div>
  
  <!-- Categories section -->
  <div class="categories-section">
    <h2 class="categories-title">Categories</h2>
    
    {% assign categories = site.tutorials | map: "categories" | flatten | uniq %}
    {% for category in categories %}
    <div class="category">
      <div class="category-header" onclick="toggleCategory(this)">
        {{ category }}
      </div>
      <div class="category-content">
        <ul class="article-list">
          {% assign category_posts = site.tutorials | where_exp: "post", "post.categories contains category" | sort: 'date' | reverse %}
          {% for post in category_posts %}
          <li class="article-item">
            <a href="{{ post.url | relative_url }}" class="article-link">
              <span class="article-date">{{ post.date | date: "%Y-%m-%d" }}</span>
              <span class="article-title-text">{{ post.title }}</span>
            </a>
            {% if post.tags.size > 0 %}
            <div class="article-tags">
              {% for tag in post.tags %}
              <span class="article-tag">{{ tag }}</span>
              {% endfor %}
            </div>
            {% endif %}
          </li>
          {% endfor %}
        </ul>
      </div>
    </div>
    {% endfor %}
  </div>
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