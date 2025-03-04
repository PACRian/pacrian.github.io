# tutorials/index.md
---
layout: default
title: Tutorials
---

{% include navigation.html %}

<div class="container">
  <h1>Tutorials List</h1>
  
  <div class="tutorial-list">
    {% assign sorted_tutorials = site.tutorials | sort: "date" | reverse %}
    {% for tutorial in sorted_tutorials %}
      <article class="tutorial-item">
        <h2>
          <a href="{{ tutorial.url | relative_url }}">
            {{ tutorial.title }}
          </a>
        </h2>
        <time datetime="{{ tutorial.date | date_to_xmlschema }}">
          {{ tutorial.date | date: "%B %-d, %Y" }}
        </time>
        <p>{{ tutorial.excerpt | strip_html | truncate: 150 }}</p>
      </article>
    {% endfor %}
  </div>
</div>

<style>
.tutorial-list {
  margin-top: 2rem;
}

.tutorial-item {
  border-bottom: 1px solid #eee;
  padding: 1.5rem 0;
}

.tutorial-item h2 {
  margin: 0 0 0.5rem;
  font-size: 1.5rem;
}

.tutorial-item time {
  color: #666;
  font-size: 0.9rem;
}

.tutorial-item p {
  margin: 0.5rem 0 0;
  color: #444;
}
</style>
