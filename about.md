---
layout: default
title: About
permalink: /about/
---

<div class="hero-section" style="padding: 100px 0; background: var(--background-color); border-bottom: 1px solid var(--border-color); text-align: center;">
    <div class="container">
        <h1 style="font-size: var(--font-size-3xl); letter-spacing: -0.02em; color: var(--text-primary);">Cristian Hoffman Martín Mondragón</h1>
        <p style="color: var(--text-secondary); opacity: 0.7; max-width: 600px; margin: 0 auto; font-weight: 300;">Electrical Engineering student at Universidad Nacional de Colombia, with a focus on control systems and power systems.</p>
    </div>
</div>

<div class="about-content">
    <div class="container">

        <section class="about-section">
            <h2>About Me</h2>
            <p>I am a final-year Electrical Engineering student at the Universidad Nacional de Colombia, passionate about control systems and power systems. My academic and project work spans from designing control loops for physical plants to analyzing real-world power grids.</p>
            <p>Before pursuing my engineering degree, I built a strong practical foundation through SENA, earning a technical diploma in Residential Electrical Installations and a technologist degree in Industrial Electricity. This hands-on background gives me a grounded perspective when tackling both theoretical and applied engineering challenges.</p>
        </section>

        <section class="about-section">
            <h2>Areas of Interest</h2>
            <div class="features-list">
                <div class="feature-item">
                    <h3><i class="fas fa-sliders-h"></i> Control Systems</h3>
                    <p>Design and implementation of control strategies for dynamic systems, including inverted pendulums, aerial platforms, and temperature regulation plants. Experience with classical and modern control techniques.</p>
                </div>
                <div class="feature-item">
                    <h3><i class="fas fa-bolt"></i> Power Systems</h3>
                    <p>Analysis of real-world electrical grids including load flow studies, economic dispatch, frequency regulation, and fault analysis. Hands-on experience with the IEEE 30-bus system, representing a section of the American Electric Power network with 335 MW of installed capacity.</p>
                </div>
                <div class="feature-item">
                    <h3><i class="fas fa-drone"></i> Aerial Systems</h3>
                    <p>Practical experience working with drones, bridging control theory with real embedded systems and flight dynamics.</p>
                </div>
            </div>
        </section>

        <section class="about-section">
            <h2>Education</h2>
            <div class="perfect-for-grid">
                <div class="perfect-for-item">
                    <h4>B.Sc. Electrical Engineering</h4>
                    <p>Universidad Nacional de Colombia<br><em>In progress — expected graduation 2027</em></p>
                </div>
                <div class="perfect-for-item">
                    <h4>Technologist in Industrial Electricity</h4>
                    <p>SENA<br><em>Completed</em></p>
                </div>
                <div class="perfect-for-item">
                    <h4>Technical Diploma in Residential Electrical Installations</h4>
                    <p>SENA<br><em>Completed</em></p>
                </div>
            </div>
        </section>

        <section class="about-section">
            <h2>Get In Touch</h2>
            <p>Feel free to reach out if you'd like to discuss projects, collaborations, or opportunities.</p>
            <div class="cta-buttons">
                <a href="mailto:crmartinm@unal.edu.co" class="btn-primary">
                    <i class="fas fa-envelope"></i> Email Me
                </a>
                <a href="https://www.linkedin.com/in/cristian-hoffman-martín-mondragon-0300461b8/" class="btn-secondary" target="_blank">
                    <i class="fab fa-linkedin"></i> LinkedIn
                </a>
                <a href="{{ '/projects/' | relative_url }}" class="btn-secondary">
                    <i class="fas fa-folder-open"></i> View My Projects
                </a>
            </div>
        </section>

    </div>
</div>

<style>
.about-content {
    padding: var(--spacing-2xl) 0;
}

.about-section {
    margin-bottom: var(--spacing-3xl);
}

.about-section h2 {
    color: var(--text-primary);
    margin-bottom: var(--spacing-lg);
    padding-bottom: var(--spacing-sm);
    border-bottom: 1px solid var(--border-color);
    font-size: var(--font-size-2xl);
    letter-spacing: -0.01em;
}

.features-list {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
    gap: var(--spacing-xl);
    margin-top: var(--spacing-lg);
}

.feature-item {
    padding: var(--spacing-lg);
    background-color: var(--surface-color);
    border-radius: var(--radius-sm);
    box-shadow: 0 4px 20px var(--shadow-color);
    transition: transform var(--transition-normal), box-shadow var(--transition-normal);
}

.feature-item:hover {
    transform: translateY(-4px);
    box-shadow: 0 12px 30px var(--shadow-hover);
}

.feature-item h3 {
    display: flex;
    align-items: center;
    gap: var(--spacing-sm);
    color: var(--text-primary);
    margin-bottom: var(--spacing-md);
}

.feature-item h3 i {
    color: var(--primary-color);
    font-size: var(--font-size-lg);
}

.perfect-for-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(220px, 1fr));
    gap: var(--spacing-lg);
    margin-top: var(--spacing-lg);
}

.perfect-for-item {
    text-align: center;
    padding: var(--spacing-lg);
    background-color: var(--surface-color);
    border-radius: var(--radius-lg);
    border: 1px solid var(--border-color);
}

.perfect-for-item h4 {
    color: var(--primary-color);
    margin-bottom: var(--spacing-sm);
}

.cta-buttons {
    display: flex;
    gap: var(--spacing-md);
    justify-content: center;
    flex-wrap: wrap;
    margin-top: var(--spacing-xl);
}

@media (max-width: 640px) {
    .features-list { grid-template-columns: 1fr; }
    .perfect-for-grid { grid-template-columns: 1fr; }
    .cta-buttons { flex-direction: column; align-items: center; }
}
</style>