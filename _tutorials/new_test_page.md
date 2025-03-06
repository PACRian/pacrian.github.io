---
layout: default
title: Test Page
date: 2025-03-04
categories: ["C++ tutorials"]
tags: ["C++", "test"]
excerpt: "TEST"
lang: en
translations: 
  - lang: zh
    url: /tutorials/void_test_page/
  - lang: en
    url: /tutorials/new_test_page/
---

<!-- Inline script to ensure translations are available -->
<script type="application/json" id="page-translations">
{{ page.translations | jsonify }}
</script>

<!-- Language toggle button -->
<button 
  class="lang-toggle-btn" 
  aria-label="Toggle Language">
  {% if page.lang == 'en' %}中文{% else %}English{% endif %}
</button>

<!-- Language toggle script -->
<script>
document.addEventListener('DOMContentLoaded', function() {
  // Ensure we have the translations
  const translationsScript = document.getElementById('page-translations');
  
  if (translationsScript) {
    try {
      const translations = JSON.parse(translationsScript.textContent);
      
      const langToggleBtn = document.querySelector('.lang-toggle-btn');
      
      if (langToggleBtn) {
        langToggleBtn.addEventListener('click', function() {
          // Get the current page's language
          const currentLang = '{{ page.lang }}';
          
          // Find the translation for the other language
          const translation = translations.find(t => t.lang !== currentLang);
          
          if (translation) {
            // Navigate to the translated page
            window.location.href = translation.url;
          }
        });
      }
    } catch (error) {
      console.error('Error parsing translations:', error);
    }
  } else {
    console.error('Translations script not found');
  }
});
</script>