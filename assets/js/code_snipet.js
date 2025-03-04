document.addEventListener('DOMContentLoaded', function() {
    // Language Identification and Badge
    const codeBlocks = document.querySelectorAll('pre code');
    codeBlocks.forEach(block => {
        // Detect language
        const languageClass = Array.from(block.classList)
            .find(cls => cls.startsWith('language-'));
        
        const language = languageClass 
            ? languageClass.replace('language-', '').toUpperCase() 
            : 'PLAIN TEXT';
        
        // Create language badge
        const badge = document.createElement('span');
        badge.classList.add('language-badge');
        badge.textContent = language;
        
        // Add badge to parent pre element
        const preBlock = block.closest('pre');
        if (preBlock) {
            preBlock.style.position = 'relative';
            preBlock.appendChild(badge);
        }
    });

    // Code Folding Enhancement
    const foldableBlocks = document.querySelectorAll('pre');
    foldableBlocks.forEach(block => {
        // Capture first line for display
        const firstLine = block.textContent.split('\n')[0];
        
        // Create folding container
        const container = document.createElement('div');
        container.classList.add('code-folding-container');
        container.setAttribute('data-first-line', firstLine);
        
        // Wrap the block
        block.parentNode.insertBefore(container, block);
        container.appendChild(block);
    });
});